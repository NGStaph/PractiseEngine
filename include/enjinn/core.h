#include "precision.h"

namespace enjinn{
    class vec_3d{
        public:
            // Holds co-ordinates
            real x, y, z;
        private:
            // Padding to ensure 4 word alignment
            real pad; 
        public:
            // Default Constructor; uses Initialiser list
            vec_3d(): x(0), y(0), z(0){}
            // Explicit constructor; uses Initialiser list
            vec_3d(const real x, const real y, const real z): x(x), y(y), z(z) {}
            // Inversion
            void invert(){
                x=-x;
                y=-y;
                z=-z;
            }
            // Return Magnitude of vector
            real magnitude() const{
                return real_sqrt(x*x+y*y+z*z);
            }
            // Return Square Magnitude
            real squareMagnitude() const{
                return x*x+y*y+z*z;
            }
            // Multiplies Vector by a given Scalar Value.
            void operator*=(const real value){
                x *=value;
                y *=value;
                z *=value;
            }
            // Returns a copy of this vector scaled the given value.
            vec_3d operator*(const real value) const{
                return vec_3d(x*value, y*value, z*value);
            }
            // Adds given vector to this.
            void operator+=(const vec_3d& v){
                x += v.x;
                y += v.y;
                z += v.z; 
            }
            // Returns value of vector added to this.
            vec_3d operator+(const vec_3d& v) const{
                return vec_3d(x+v.x, y+v.y, z+v.z);
            }
            // Subtracts vector by this value
            void operator-=(const vec_3d& v){
                x -= v.x;
                y -= v.y;
                z -= v.z;
            }
            // Retrun value of vector subtracted from this.
            vec_3d operator-(const vec_3d& v){
                return vec_3d(x-v.x, y-v.y,z-v.z);
            }
            // Vector Normalization. Extract Basis/Unit Vector
            void normalize(){
                real l = magnitude();
                if (l>0){
                    (*this) *= ((real)1)/l;
                }
            }
            

    };
}