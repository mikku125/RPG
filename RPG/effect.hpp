#ifndef EFFECT_HPP
#define EFFECT_HPP

namespace RPG
{
    class Effect
    {
    protected:
        int incHp;
        int incMp;
        int incDmg;
        int repHp;
        int repMp;

    public:
        Effect(const int& h=0, const int& m=0, const int& d=0, const int& rh=0, const int& rm=0)
        : incHp(h), incMp(m), incDmg(d), repHp(rh), repMp(rm)
        {}

        virtual void info() const;

        virtual ~Effect(){};
    };
}
#endif // EFFECT_HPP
