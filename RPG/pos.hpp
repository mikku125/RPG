#ifndef POS_HPP
#define POS_HPP

namespace Rpg
{
    class Pos
    {
    protected:
        unsigned xpos;
        unsigned ypos;

    public:
        Pos(unsigned x = 0, unsigned y = 0)
        : xpos(x), ypos(y) {}

        Pos getPos()
        {
            return *this;
        }

        unsigned getX() const
        {
            return xpos;
        }

        unsigned getY() const
        {
            return ypos;
        }

        ~Pos() {}
    };

    inline bool operator ==(const Pos& p1, const Pos& p2)
    {
        return ( (p1.getX() == p2.getX() ) && (p1.getY() == p2.getY() ) );
    }

    inline bool operator !=(const Pos& p1, const Pos& p2)
    {
        return !(p1 == p2);
    }
}
#endif // POS_HPP
