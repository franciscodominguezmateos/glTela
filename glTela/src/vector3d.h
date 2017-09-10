//**********************************************************************
//* Vector.h
//* 
//* Just Another Vector Implementation (JAVI)
//**********************************************************************

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <cmath>
#include <ostream>
#include <cassert>

class Vector3D
{
public:
    //******************************************************************
    //* Constructors
    //******************************************************************
    // Default Constructor
    //------------------------------------------------------------------
    // Sets the x, y and z components of this Vector to zero.
    //------------------------------------------------------------------
    Vector3D ();
    //------------------------------------------------------------------
    // Component Constructor
    //------------------------------------------------------------------
    // Sets the x, y and z components of this Vector to corresponding 
    // x, y and z parameters.
    //------------------------------------------------------------------
    Vector3D (double x, double y, double z);
    //------------------------------------------------------------------
    // Copy Constructor
    //------------------------------------------------------------------
    // Sets the x, y and z components of this Vector to equal the x, y 
    // and z components of Vector v.
    //------------------------------------------------------------------
    Vector3D (const Vector3D &v);
    //******************************************************************

    //******************************************************************
    //* Friend Operators
    //******************************************************************
    // Stream Insertion Operator
    //------------------------------------------------------------------
    // Writes the Vector v into the output stream in the format (x,y,z) 
    // so it can be used by various iostream functions.
    //------------------------------------------------------------------
    friend std::ostream &operator << (std::ostream &os, const Vector3D &v);
    //------------------------------------------------------------------
    // Equal To Operator
    //------------------------------------------------------------------
    // Compares the x, y and z components of Vector v1 and to the x, y 
    // and z components of Vector v2 and returns true if they are 
    // identical. Otherwise, it returns false.
    //------------------------------------------------------------------
    friend bool operator == (const Vector3D &v1, const Vector3D &v2);
    //------------------------------------------------------------------
    // Not Equal To Operator
    //------------------------------------------------------------------
    // Compares the x, y and z components of Vector v1 and to the x, y 
    // and z components of Vector v2 and returns true if they are not 
    // identical. Otherwise, it returns false.
    //------------------------------------------------------------------
    friend bool operator != (const Vector3D &v1, const Vector3D &v2);
    //------------------------------------------------------------------
    // Addition Operator
    //------------------------------------------------------------------
    // Adds the x, y and z components of Vector v1 to the x, y and z 
    // compenents of Vector v2 and returns the result.
    //------------------------------------------------------------------
    friend Vector3D operator + (const Vector3D &v1, const Vector3D &v2);
    //------------------------------------------------------------------
    // Subtraction Operator
    //------------------------------------------------------------------
    // Subtracts the x, y and z components of Vector v2 to the x, y and 
    // z compenents of Vector v1 and returns the result.
    //------------------------------------------------------------------
    friend Vector3D operator - (const Vector3D &v1, const Vector3D &v2);
    //------------------------------------------------------------------
    // Multiplication Operator
    //------------------------------------------------------------------
    // Multiplies the x, y and z components of Vector v with a scalar 
    // value and returns the result.
    //------------------------------------------------------------------
    friend Vector3D operator * (const Vector3D &v, double scalar);
    friend Vector3D operator * (double scalar, const Vector3D &v);
    //------------------------------------------------------------------
    // Division Operator
    //------------------------------------------------------------------
    // Divides the x, y and z components of Vector v with a scalar 
    // value and returns the result.
    //------------------------------------------------------------------
    friend Vector3D operator / (const Vector3D &v, double scalar);
    friend Vector3D operator / (double scalar, const Vector3D &v);
    //******************************************************************

    //******************************************************************
    //* Friend Functions
    //******************************************************************
    // DotProduct
    //------------------------------------------------------------------
    // Computes the dot product between Vector v1 and Vector v2 and 
    // returns the result.
    // two implementations, * can make ambiguity
    //------------------------------------------------------------------
    friend double dotProduct (const Vector3D &v1, const Vector3D &v2);
    friend double operator * (const Vector3D &v1, const Vector3D &v2);
    //------------------------------------------------------------------
    // CrossProduct
    //------------------------------------------------------------------
    // Computes the cross product between Vector v1 and Vector v2 and 
    // returns the result.
    //------------------------------------------------------------------
    friend Vector3D crossProduct (const Vector3D &v1, const Vector3D &v2);
    //------------------------------------------------------------------
    // Lerp
    //------------------------------------------------------------------
    // Returns a linear interpolation between Vector v1 and Vector v2 
    // for paramater t, in the closed interval [0, 1].
    //------------------------------------------------------------------
    friend Vector3D lerp (const Vector3D &v1, const Vector3D &v2, double t);
    //------------------------------------------------------------------
    // Clamp - TODO: make this a method instead?
    //------------------------------------------------------------------
    // Clamps this Vector's x, y and z components to lie within min and 
    // max.
    //------------------------------------------------------------------
    friend Vector3D clamp (const Vector3D &v1, double min, double max);
    //------------------------------------------------------------------
    // Min
    //------------------------------------------------------------------
    // Returns a Vector whos x, y and z components are the minimum 
    // components found in Vector v1 and Vector v2.
    //------------------------------------------------------------------
    friend Vector3D min (const Vector3D &v1, const Vector3D &v2);
    //------------------------------------------------------------------
    // Max
    //------------------------------------------------------------------
    // Returns a Vector whos x, y and z components are the maximum 
    // components found in Vector v1 and Vector v2.
    //------------------------------------------------------------------
    friend Vector3D max (const Vector3D &v1, const Vector3D &v2);
    //------------------------------------------------------------------
    // DistanceBetween
    //------------------------------------------------------------------
    // Returns the scalar distance between the Vector v1 and the Vector 
    // v2.
    //------------------------------------------------------------------
    friend double distanceBetween (const Vector3D &v1, const Vector3D &v2);
    //------------------------------------------------------------------
    // DistanceBetweenSquared
    //------------------------------------------------------------------
    // Returns the scalar squared distance between the Vector v1 and 
    // the Vector v2.
    //------------------------------------------------------------------
    friend double distanceBetweenSquared (const Vector3D &v1, const Vector3D &v2);
    //******************************************************************

    //******************************************************************
    //* Operators
    //******************************************************************
    // Copy Assignment Operator
    //------------------------------------------------------------------
    // Assigns this Vector's components to be equal to Vector v's 
    // components.
    //------------------------------------------------------------------
    Vector3D &operator = (const Vector3D &v);
    //------------------------------------------------------------------
    // Addition Assignment Operator
    //------------------------------------------------------------------
    // Adds to this Vector's components the components of Vector v.
    //------------------------------------------------------------------
    Vector3D &operator += (const Vector3D &v);
    //------------------------------------------------------------------
    // Subtraction Assignment Operator
    //------------------------------------------------------------------
    // Subtract from this Vector's components the components of Vector 
    // v.
    //------------------------------------------------------------------
    Vector3D &operator -= (const Vector3D &v);
    //------------------------------------------------------------------
    // Multiplication Assignment Operator
    //------------------------------------------------------------------
    // Multiply this Vector's components by a scalar value.
    //------------------------------------------------------------------
    Vector3D &operator *= (double scalar);
    //------------------------------------------------------------------
    // Division Assignment Operator
    //------------------------------------------------------------------
    // Divide this Vector's components by a scalar value.
    //------------------------------------------------------------------
    Vector3D &operator /= (double scalar);
    //------------------------------------------------------------------
    // Unary Minus Operator
    //------------------------------------------------------------------
    // Negate the components of this Vector.
    //------------------------------------------------------------------
    Vector3D &operator - ();
    //------------------------------------------------------------------
    // Array Subscript Operator
    //------------------------------------------------------------------
    // Allows access to the x, y and z components through an array 
    // subscript notation.
    //------------------------------------------------------------------
    double &operator [] (int i);
    //******************************************************************

    //******************************************************************
    //* Methods
    //******************************************************************
    // X
    //------------------------------------------------------------------
    // Returns the x component of this Vector.
    //------------------------------------------------------------------
    double getX ();
    //------------------------------------------------------------------
    // Y
    //------------------------------------------------------------------
    // Returns the y component of this Vector.
    //------------------------------------------------------------------
    double getY ();
    //------------------------------------------------------------------
    // Z
    //------------------------------------------------------------------
    // Returns the z component of this Vector.
    //------------------------------------------------------------------
    double getZ ();
    //------------------------------------------------------------------
    // Set
    //------------------------------------------------------------------
    // Sets the x, y and z components of this Vector to the paramaters 
    // of this function.
    //------------------------------------------------------------------
    void set (double x, double y, double z);
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    //------------------------------------------------------------------
    // MakeZero
    //------------------------------------------------------------------
    // Sets the x, y and z components of this Vector to zero.
    //------------------------------------------------------------------
    void makeZero ();
    //------------------------------------------------------------------
    // IsZero
    //------------------------------------------------------------------
    // Returns true if the x, y and z components of this Vector are 
    // equal to zero.
    //------------------------------------------------------------------
    bool isZero ();
    //------------------------------------------------------------------
    // LengthSquared
    //------------------------------------------------------------------
    // Returns the magnitude of the x, y and z components squared.
    //------------------------------------------------------------------
    double lengthSquared ();
    //------------------------------------------------------------------
    // Length
    //------------------------------------------------------------------
    // Returns the magnitude of the x, y and z components.
    //------------------------------------------------------------------
    double length ();
    //------------------------------------------------------------------
    // Normalize
    //------------------------------------------------------------------
    // Sets the components of this Vector in such a way that their 
    // magnitude is equal to one.
    //------------------------------------------------------------------
    void normalize ();
    Vector3D normalized ();
     //------------------------------------------------------------------
    // Reflect
    //------------------------------------------------------------------
    // Reflect this vector in the normal n
    // n must be normalized
    //------------------------------------------------------------------
    Vector3D reflect(Vector3D n);
    //------------------------------------------------------------------
    // IsNormalized
    //------------------------------------------------------------------
    // Compares the magnitude of this Vector to one.
    //------------------------------------------------------------------
    bool isNormalized ();
    //******************************************************************

private:
    //******************************************************************
    //* Private Member Variables
    //******************************************************************
    // x
    //------------------------------------------------------------------
    // The x component of this Vector.
    //------------------------------------------------------------------
    double x;
    //------------------------------------------------------------------
    // y
    //------------------------------------------------------------------
    // The y component of this Vector.
    //------------------------------------------------------------------
    double y;
    //------------------------------------------------------------------
    // z
    //------------------------------------------------------------------
    // The z component of this Vector.
    //------------------------------------------------------------------
    double z;
    //******************************************************************
};

inline Vector3D::Vector3D() : x(0.0f), y(0.0f), z(0.0f) {}

inline Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

inline Vector3D::Vector3D(const Vector3D &v) : x(v.x), y(v.y), z(v.z) {}

inline std::ostream &operator<<(std::ostream &os, const Vector3D &v){
    os << '<' << v.x << ',' << v.y << ',' << v.z << '>';
    return os;
}

inline bool areEqual(double a,double b){
	return a==b;
}
inline bool operator==(const Vector3D &v1, const Vector3D &v2){
    return (areEqual(v1.x, v2.x) &&
            areEqual(v1.y, v2.y) &&
            areEqual(v1.z, v2.z));
}

inline bool operator!=(const Vector3D &v1, const Vector3D &v2){
    return (!areEqual(v1.x, v2.x) ||
            !areEqual(v1.y, v2.y) ||
            !areEqual(v1.z, v2.z));
}

inline Vector3D operator+(const Vector3D &v1, const Vector3D &v2){
    return Vector3D(v1.x+v2.x, v1.y+v2.y, v1.z+v2.z);
}

inline Vector3D operator-(const Vector3D &v1, const Vector3D &v2){
    return Vector3D(v1.x-v2.x, v1.y-v2.y, v1.z-v2.z);
}

inline Vector3D operator*(const Vector3D &v, double scalar){
    return Vector3D(v.x*scalar, v.y*scalar, v.z*scalar);
}

inline Vector3D operator*(double scalar, const Vector3D &v){
    return Vector3D(v.x*scalar, v.y*scalar, v.z*scalar);
}

inline bool equalsZero(double a){
	//double almost never is 0.0
	//This value shoud be a const
	return fabs(a)<1e-30;
}

inline Vector3D operator/(const Vector3D &v, double scalar){
    assert(!equalsZero(scalar));
    scalar = 1.0f / scalar;
    return Vector3D(v.x*scalar, v.y*scalar, v.z*scalar);
}

inline Vector3D operator/(double scalar, const Vector3D &v){
    assert(!equalsZero(scalar));
    scalar = 1.0f / scalar;
    return Vector3D(v.x*scalar, v.y*scalar, v.z*scalar);
}

inline double operator * (const Vector3D &v1, const Vector3D &v2){
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
inline double dotProduct (const Vector3D &v1, const Vector3D &v2){
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline Vector3D crossProduct(const Vector3D &v1, const Vector3D &v2){
    return Vector3D(v1.y*v2.z - v1.z*v2.y,
                  v1.z*v2.x - v1.x*v2.z,
                  v1.x*v2.y - v1.y*v2.x);
}

inline double lerp(double a,double b,double t){
	return a+(b-a)*t;
}
inline Vector3D lerp(const Vector3D &v1, const Vector3D &v2, double t){
    return Vector3D(lerp(v1.x, v2.x, t),
                    lerp(v1.y, v2.y, t),
                    lerp(v1.z, v2.z, t));
}
inline double clamp(double a,double min,double max){
	double m=fmax(a,min);
	return fmin(m,max);
}

inline Vector3D clamp(const Vector3D &v, double min, double max){
    return Vector3D(clamp(v.x, min, max),
                    clamp(v.y, min, max),
                    clamp(v.z, min, max));
}

inline Vector3D min(const Vector3D &v1, const Vector3D &v2){
    return Vector3D(fmin(v1.x, v2.x),
                    fmin(v1.y, v2.y),
                    fmin(v1.z, v2.z));
}

inline Vector3D max(const Vector3D &v1, const Vector3D &v2){
    return Vector3D(fmax(v1.x, v2.x),
                    fmax(v1.y, v2.y),
                    fmax(v1.z, v2.z));
}

inline double distanceBetween(const Vector3D &v1, const Vector3D &v2){
    Vector3D distance = v1 - v2;
    return distance.length();
}

inline double distanceBetweenSquared (const Vector3D &v1, const Vector3D &v2){
    Vector3D distance = v1 - v2;
    return distance.lengthSquared();
}

inline Vector3D &Vector3D::operator=(const Vector3D &v){
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
} 

inline Vector3D &Vector3D::operator+=(const Vector3D &v){
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

inline Vector3D &Vector3D::operator-=(const Vector3D &v){
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

inline Vector3D &Vector3D::operator*=(double scalar){
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

inline Vector3D &Vector3D::operator/=(double scalar){
    assert(!equalsZero(scalar));
    scalar = 1.0f / scalar;
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

inline Vector3D &Vector3D::operator-(){
    x = -x;
    y = -y;
    z = -z;
    return *this;
}

inline double &Vector3D::operator[](int i){
    if (i == 0) {
        return x;
    } else if (i == 1) {
        return y;
    } else if (i == 2) {
        return z;
    } else {
        assert("[] Access error!");
    }
    return x;
}

inline double Vector3D::getX(){
    return x;
}

inline double Vector3D::getY(){
    return y;
}

inline double Vector3D::getZ(){
    return z;
}

inline void Vector3D::set(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}
inline void Vector3D::setY(double y){
    this->y = y;
}
inline void Vector3D::setX(double x){
    this->x = x;
}
inline void Vector3D::setZ(double z){
    this->z = z;
}

inline void Vector3D::makeZero(){
    x = y = z = 0.0f;
}

inline bool Vector3D::isZero(){
    return equalsZero(x) &&
           equalsZero(y) &&
           equalsZero(z);
}

inline double Vector3D::lengthSquared(){
    return x*x + y*y + z*z;
}

inline double Vector3D::length(){
    return sqrt(lengthSquared());
}

inline void Vector3D::normalize(){
    double magnitude = length();
    assert(!equalsZero(magnitude));

    magnitude = 1.0f / magnitude;

    x *= magnitude;
    y *= magnitude;
    z *= magnitude;
}
inline Vector3D Vector3D::normalized(){
	Vector3D r;
    double magnitude = length();
    assert(!equalsZero(magnitude));

    magnitude = 1.0f / magnitude;

    r.x=x * magnitude;
    r.y=y * magnitude;
    r.z=z * magnitude;
    return r;
}

inline Vector3D Vector3D::reflect(Vector3D n){
	Vector3D self,projectionV,dif,reflectedV,newV;
	double projectionN;
	self=*this;
	projectionN=self*n;
	projectionV=projectionN*n;
	dif=self+projectionV;
	reflectedV=-projectionV;
	newV=dif+reflectedV;
	return newV;
}
inline bool Vector3D::isNormalized(){
    return areEqual(length(), 1.0f);
}

#endif
