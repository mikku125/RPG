#ifndef EFFECT_HPP
#define EFFECT_HPP

namespace Rpg
{
    class Effect
    {
    protected:
        int incHp;
        int incDmg;
        int repHp;

    public:
        Effect(int h=0, int d=0, int rh=0)
        : incHp(h), incDmg(d), repHp(rh)
        {}

        int& getIncHp()
        {
            return incHp;
        }

        int& getIncDmg()
        {
            return incDmg;
        }

        int& getRepHp()
        {
            return repHp;
        }

        virtual void info() const;

        virtual ~Effect(){};
    };
}
#endif // EFFECT_HPP
