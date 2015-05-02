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
        Pos(unsigned x=0, unsigned y=0)
        : xpos(x), ypos(y) {}

        Pos& getPos()
        {
            return *this;
        }

        unsigned& getXpos()
        {
            return xpos;
        }

        unsigned& getYpos()
        {
            return ypos;
        }

        friend bool operator==(const Pos&, const Pos&);

        friend bool operator!=(const Pos&, const Pos&);

        ~Pos() {}
    };

    inline bool operator==(const Pos& p1, const Pos& p2)
    {
        return ( (p1.xpos==p2.xpos) && (p1.ypos==p2.ypos) );
    }

    inline bool operator!=(const Pos& p1, const Pos& p2)
    {
        return !(p1==p2);
    }
}
#endif // POS_HPP
