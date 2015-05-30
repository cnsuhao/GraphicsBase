#pragma once
#include<math.h>

class Vector3
{
public:
	Vector3();
	~Vector3();

	float x, y, z;
	//copy constructor
	Vector3(const Vector3 &v) : x(v.x), y(v.y), z(v.z){}
	//constructor with parameters
	Vector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz){}
	
	Vector3& operator=(const Vector3 &v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	bool operator==(const Vector3 &a) const
	{
		return x == a.x && y == a.y && z == a.z;
	}

	bool operator!=(const Vector3& a) const
	{
		return x != a.x || y != a.y || z != a.z;
	}

	//set self to zero vector
	void zero()
	{
		x = y = z = 0.0f;
	}

	//获取当前向量的负向量
	Vector3 operator-() const
	{
		return Vector3(-x, -y, -z);
	}

	Vector3 operator+(const Vector3 &a) const
	{
		return Vector3(x + a.x, y + a.y, z + a.z);
	}

	Vector3 operator-(const Vector3 &a) const
	{
		return Vector3(x - a.x, y - a.y, z - a.z);
	}

	Vector3 operator*(float a) const
	{
		return Vector3(x*a, y*a, z*a);
	}

	Vector3 operator/(float a) const
	{
		float oneOverA = 1.0f / a; //not check whether a is 0
		return Vector3(x*oneOverA, y*oneOverA, z*oneOverA);
	}

	Vector3& operator+=(const Vector3& a)
	{
		x += a.x;
		y += a.y;
		z += a.z;
		return *this;
	}

	Vector3& operator-=(const Vector3& a)
	{
		x -= a.x;
		y -= a.y;
		z -= a.z;
		return *this;
	}

	Vector3& operator*=(float a)
	{
		x *= a;
		y *= a;
		z *= a;
		return *this;
	}

	Vector3& operator/=(float a)
	{
		float oneOverA = 1.0f / a;
		x *= oneOverA;
		y *= oneOverA;
		z *= oneOverA;
		return *this;
	}

	//normalized itself
	void normalize()
	{
		float magSq = x*x + y*y + z*z;
		if (magSq > 0.0f) //检查除0
		{
			float oneOverMag = 1.0f / sqrt(magSq);
			x *= oneOverMag;
			y *= oneOverMag;
			z *= oneOverMag;
		}
	}

	//向量点乘,点乘的结果描述了两个向量的“相似”程度，点乘结果越大，两个向量越接近
	float operator*(const Vector3& a) const
	{
		return x*a.x + y*a.y + z*a.z;
	}
};

//非成员函数

//向量求模(长度)
inline float vectorMag(const Vector3& a)
{
	return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

//向量叉乘
inline Vector3 crossProduct(const Vector3& a, const Vector3& b)
{
	return Vector3(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

//实现标量左乘
inline Vector3 operator*(float k, const Vector3& v)
{
	return Vector3(k*v.x, k*v.y, k*v.z);
}

//计算两点间的距离
inline float distance(const Vector3& a, const Vector3& b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;
	return sqrt(dx*dx + dy*dy + dz*dz);
}

//全局变量,零向量
extern const Vector3 kZeroVector;


