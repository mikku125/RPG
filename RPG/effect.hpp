#ifndef EFFECT_HPP
#define EFFECT_HPP

#include "unit.hpp"

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

        virtual void info() const;

        void applyEffects(Unit*);

        virtual ~Effect(){};
    };
}
#endif // EFFECT_HPP
