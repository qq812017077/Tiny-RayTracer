#pragma once
#include "Vector.h"

struct Matrix4x4
{
private:
    float data[4][4];

public:
    Matrix4x4();
    Matrix4x4(float* data);
    Matrix4x4(float data[4][4]);
    Matrix4x4(float a1, float a2, float a3, float a4,
        float b1, float b2, float b3, float b4,
        float c1, float c2, float c3, float c4,
        float d1, float d2, float d3, float d4);
    Matrix4x4(float a[4], float b[4], float c[4], float d[4]);
    Matrix4x4(Vector4& a, Vector4& b, Vector4& c, Vector4& d);
    ~Matrix4x4() = default;
    Matrix4x4(Matrix4x4 const& other) = default;
    Matrix4x4& operator=(Matrix4x4& other) noexcept;

    Matrix4x4 operator*(float val) const;
    Matrix4x4 operator*(Matrix4x4& other) const;
    Vector4 operator*(Vector4& other) const;
    Vector4 operator*(Vector4& other);
    float* operator[](int index);
    float* operator[](int row_index) const;
    void SetData(float* data);
    void SetData(float data[4][4]);
    float* GetData();
    float GetData(int row, int column) const;
    void SetData(int row, int column, float value);

    Matrix4x4 Transpose() const;
    Matrix4x4 Inverse() const;
    float Determinant() const;
        
    void Matrix4x4::printMat4x4();


    static Matrix4x4 Identity();
    static Matrix4x4 Zero() { return Matrix4x4(); }
    static Matrix4x4 Translation(const Vector3& translation);
    static Matrix4x4 Rotation(Vector3 eulerAngle);
    static Matrix4x4 LookRotation(Vector3 forward, Vector3 up);
    static Matrix4x4 Scale(const Vector3& scale);
    static Matrix4x4 LookAtLH(Vector3 eye, Vector3 target, Vector3 up);
    static Matrix4x4 LookAtRH(Vector3 eye, Vector3 target, Vector3 up);
    static Matrix4x4 Perspective(float fov, float aspect, float near, float far);
    static Matrix4x4 OrthographicLH(float viewWidth, float viewHeight, float zNear, float zFar);
    static Matrix4x4 OrthographicLH(float left, float right, float bottom, float top, float near, float far);
};

struct Matrix3x3
{
private:
    float data[3][3];
public:
    Matrix3x3();
    Matrix3x3(float* data);
    Matrix3x3(float data[3][3]);
    Matrix3x3(Vector3 a, Vector3 b, Vector3 c);
    ~Matrix3x3() = default;
    Matrix3x3(Matrix3x3 const& other) = default;
    Matrix3x3& operator=(Matrix3x3& other) noexcept;

    Matrix3x3 operator+(Matrix3x3& other) const;
    Matrix3x3& operator+=(Matrix3x3& other);
    Matrix3x3 operator*(float val) const;
    Matrix3x3 operator*(Matrix3x3& other) const;
    Vector3 operator*(Vector3& other) const;
    Vector3 operator*(const Vector3& other) const;
    float* operator[](int row_index);
    float* operator[](int row_index) const;
    
    
    void SetData(float* data);
    void SetData(float data[3][3]);
    float* GetData();
    float GetData(int row, int column) const;
    void SetData(int row, int column, float value);

    Matrix3x3 Transpose() const;
    Matrix3x3 Inverse() const;
    float Determinant() const;

    void Matrix3x3::printMat3x3();


    static Matrix3x3 Identity();
    static Matrix3x3 Zero() { return Matrix3x3(); }
    /**
     * @brief Rotation Matrix: rotate by an angle around an axis(Rodrigues' rotation formula)
     * 
     * @param angle 
     * @param axis 
     * @return Matrix3x3
     */
    static Matrix3x3 Rotation(const Vector3& eulerAngle);
    static Matrix3x3 RotateByAxis(float angle, const Vector3& axis);
    static Matrix3x3 VectorProduct(const Vector3& vec1, const Vector3& vec2);
    static Matrix3x3 LookAt(const Vector3& eye, const Vector3& target, const Vector3& up);
};