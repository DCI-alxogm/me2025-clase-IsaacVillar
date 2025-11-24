#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multifit_nlinear.h>

struct data {
    size_t n;
    double *aw;
    double *me;
};

// Definición del modelo de Peleg: y = b0 * aw^b1 + b2 * aw^b3
int peleg_f(const gsl_vector * x, void *data, gsl_vector * f) {
    size_t n = ((struct data *)data)->n;
    double *aw = ((struct data *)data)->aw;
    double *me = ((struct data *)data)->me;

    double b0 = gsl_vector_get(x, 0);
    double b1 = gsl_vector_get(x, 1);
    double b2 = gsl_vector_get(x, 2);
    double b3 = gsl_vector_get(x, 3);

    for (size_t i = 0; i < n; i++) {
        double Yi = b0 * pow(aw[i], b1) + b2 * pow(aw[i], b3);
        gsl_vector_set(f, i, Yi - me[i]);
    }
    return GSL_SUCCESS;
}

void solve_peleg(double *aw_data, double *me_data, size_t n) {
    // Configuración del solver
    const gsl_multifit_nlinear_type *T = gsl_multifit_nlinear_trust;
    gsl_multifit_nlinear_workspace *w;
    gsl_multifit_nlinear_fdf fdf;
    gsl_multifit_nlinear_parameters fdf_params = gsl_multifit_nlinear_default_parameters();

    struct data d = { n, aw_data, me_data };
    double x_init[4] = { 2.0, 0.5, 20.0, 10.0 }; // Estimación inicial
    gsl_vector_view x = gsl_vector_view_array(x_init, 4);

    fdf.f = peleg_f;
    fdf.df = NULL;
    fdf.fvv = NULL;
    fdf.n = n;
    fdf.p = 4;
    fdf.params = &d;

    w = gsl_multifit_nlinear_alloc(T, &fdf_params, n, 4);
    gsl_multifit_nlinear_init(&x.vector, &fdf, w);

    int status, info;
    status = gsl_multifit_nlinear_driver(100, 1e-8, 1e-8, 1e-8, NULL, NULL, &info, w);

    printf("Estado del ajuste: %s\n", gsl_strerror(status));
    printf("Parámetros (b0, b1, b2, b3): %g, %g, %g, %g\n", 
           gsl_vector_get(w->x, 0), gsl_vector_get(w->x, 1), 
           gsl_vector_get(w->x, 2), gsl_vector_get(w->x, 3));
    printf("Chi2: %g\n", gsl_blas_dnrm2(w->f) * gsl_blas_dnrm2(w->f));

    gsl_multifit_nlinear_free(w);
}

int main() {
    // Ejemplo: Datos para Roasted Beans a 45C (extracto)
    double aw[] = {0.0965, 0.2708, 0.4388, 0.5639, 0.7019, 0.8124}; 
    double me[] = {2.11, 2.13, 2.17, 2.21, 5.15, 12.05}; 
    size_t n = sizeof(aw) / sizeof(aw[0]);

    solve_peleg(aw, me, n);
    return 0;
}
