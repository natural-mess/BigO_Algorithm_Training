#include <bits/stdc++.h>
using namespace std;

/*
 * Intermediate Value Theorem (IVT)
 * --------------------------------
 * If a function f(x) is continuous on a closed interval [a, b] 
 * and f(a) * f(b) <= 0, there exists at least one value c in [a, b]
 * such that f(c) = 0.
 *
 * Significance:
 * - The theorem guarantees that the root of the equation f(x) = 0 lies
 *   within the interval [a, b] if f(a) and f(b) have opposite signs.
 * - This is the foundation of the Bisection Method, which iteratively
 *   reduces the interval [a, b] to converge to a root.
 *
 * Applications:
 * - Solving equations f(x) = 0 within a specific interval [a, b].
 * - Ensures that the root exists as long as the function f(x) is continuous.
 *
 * Conditions:
 * - The function f(x) must be continuous on the interval [a, b].
 * - f(a) and f(b) must have opposite signs (f(a) * f(b) <= 0).
 *
 * Bisection Method
 * ----------------
 * The Bisection Method is a numerical approach to find a root of a 
 * continuous function f(x) within a given interval [a, b]. It is based 
 * on the Intermediate Value Theorem.
 *
 * Steps:
 * 1. Check if f(a) * f(b) <= 0. If not, the method cannot be applied.
 * 2. Compute the midpoint m = (a + b) / 2.
 * 3. Evaluate f(m):
 *    - If f(m) == 0 (or close enough to 0), m is the root.
 *    - If f(m) has the same sign as f(a), update a = m.
 *    - Otherwise, update b = m.
 * 4. Repeat steps 2-3 until the interval [a, b] becomes sufficiently small
 *    (b - a < epsilon).
 *
 * Notes:
 * - The smaller the epsilon, the higher the precision of the solution.
 * - The method is simple and guarantees convergence, but can be slow
 *   compared to other numerical methods like Newton's method.
 */


double f (double p, double q, double r, double s, double t, double u, double x)
{
    return (p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u);
}

int main()
{
    double p, q, r, s, t, u;
    while (cin >> p >> q >> r >> s >> t >> u)
    {
        double left = 0.0, right=1.0, mid;
        
        if (f(p,q,r,s,t,u,left) * f(p,q,r,s,t,u,right) > 0.0)
        {
            cout << "No solution" << endl;
            continue;
        }
        const double epsilon = 1e-8;
        while (right - left > epsilon)
        {
            mid = (left + right)/2.0;
            if (f(p, q, r, s, t, u, left) * f(p, q, r, s, t, u, mid) <= 0)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        cout << fixed << setprecision(4) << (left+right)/2.0 << endl;
    }

    return 0;
}