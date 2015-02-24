#ifndef _POINT_H_
#define _POINT_H_

#include <cmath>
#include <string>

/**
 * Class template point
 * define a point into referential
 */
template<typename T = float>
class Point
{
public:
    Point(T x = static_cast<T>(0), T y = static_cast<T>(0))
        : m_x(x),
        m_y(y)
    {}

    Point(const Point& p)
        : m_x(p.m_x),
        m_y(p.m_y)
    {}

    Point& operator=(const Point& p)
    {
        if (this != &p)
        {
            m_x = p.m_x;
            m_y = p.m_y;
        }

        return *this;
    }

    ~Point(){}

    Point& operator+=(const Point& p)
    {
        m_x += p.m_x;
        m_y += p.m_y;

        return *this;
    }

    Point operator+(const Point& p) const
    {
        Point res(*this);

        res += p;

        return res;
    }

    Point& operator -=(const Point& p)
    {
        m_x -= p.m_x;
        m_y -= p.m_y;

        return *this;
    }

    Point operator-(const Point& p) const
    {
        Point res(*this);

        res -= p;

        return res;
    }

    Point& operator/=(float f)
    {
        m_x = static_cast<T>(m_x * f);
        m_y = static_cast<T>(m_y * f);
    }

    Point operator/(float f) const
    {
        Point res(*this);

        res /= f;

        return res;
    }

    Point& operator*=(float f)
    {
        m_x = static_cast<T>(m_x * f);
        m_y = static_cast<T>(m_y * f);

        return *this;
    }

    Point operator*(float f) const
    {
        Point res(*this);

        res *= f;

        return res;
    }

    Point operator-()
    {
        return Point(-m_x, -m_y);
    }

    T getX() const
    {
        return m_x;
    }

    T getY() const
    {
        return m_y;
    }

    void setX(T x)
    {
        m_x = x;
    }

    void setY(T y)
    {
        m_y = y;
    }

    void set(T x, T y)
    {
        m_x = x;
        m_y = y;
    }

    T sqrMagnitude()
    {
        return m_x * m_x + m_y * m_y;
    }

    T magnitude()
    {
        return static_cast<T>(sqrt(sqrMagnitude()));
    }

    std::string toString() const
    {
        return std::string("(") + std::to_string(m_x) + std::string(", ") + std::to_string(m_y) + std::string(")");
    }

    Point normalise() const
    {
        Point p(*this);
        T length = p.magnitude();

        p.m_x /= length;
        p.m_y /= length;

        return p;
    }

protected:
    T m_x;
    T m_y;
};

#endif //_POINT_H_