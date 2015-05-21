#ifndef HEADER_Vec2i_CLASS
#define HEADER_Vec2i_CLASS

namespace cheesechase
{
    class Vec2i
	{
	public:
        Vec2i();
        Vec2i(int x, int y);

        int getX() const;
        int getY() const;

        double lenght() const;
        int lenghtSqrd() const;

        void setX(int x);
        void setY(int y);

        void add(Vec2i const& rhs);
        void add(int rhs);

        void sub(Vec2i const& rhs);
        void sub(int rhs);

        void div(Vec2i const& rhs);
        void div(int rhs);

        void mult(Vec2i const& rhs);
        void mult(int rhs);

        int point(Vec2i const& rhs);

    private:
        int x;
        int y;
	};

    Vec2i operator+(Vec2i const& lhs, Vec2i const& rhs);
    Vec2i operator+(Vec2i const& lhs, int rhs);
    Vec2i operator+(int lhs, Vec2i const& rhs);

    Vec2i operator-(Vec2i const& lhs, Vec2i const& rhs);
    Vec2i operator-(Vec2i const& lhs, int rhs);
    Vec2i operator-(int lhs, Vec2i const& rhs);

    Vec2i operator*(Vec2i const& lhs, Vec2i const& rhs);
    Vec2i operator*(int lhs, Vec2i const& rhs);
    Vec2i operator*(Vec2i const& lhs, int rhs);

    Vec2i operator/(Vec2i const& lhs, Vec2i const& rhs);
    Vec2i operator/(int lhs, Vec2i const& rhs);
    Vec2i operator/(Vec2i const& lhs, int rhs);

    int point(Vec2i const& lhs, Vec2i const& rhs);
}

#endif
