#ifndef POS_HPP
#define POS_HPP

namespace RPG
{
    class Pos
    {
    protected:
        unsigned xpos;
        unsigned ypos;

    public:
        Pos(const unsigned x=0, const unsigned y=0)
        : xpos(x), ypos(y)
        {}

        const unsigned& getXpos() const
        {
            return xpos;
        }

        const unsigned& getYpos() const
        {
            return ypos;
        }

        const Pos& getPos() const
        {
            return *this;
        }

        void setXpos(const unsigned& x)
        {
            xpos = x;
        }

        void setYpos(const unsigned& y)
        {
            ypos = y;
        }

        friend bool operator==(const Pos& pos1,const Pos& pos2)
        {
            return (pos1.xpos==pos2.xpos && pos1.ypos==pos2.ypos );
        }

        friend bool operator!=(const Pos& pos1,const Pos& pos2)
        {
            return !(pos1==pos2);
        }
    };
}

#endif // POS_HPP
