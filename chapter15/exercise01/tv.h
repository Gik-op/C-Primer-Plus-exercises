#ifndef EXERCISE01_TV_H
#define EXERCISE01_TV_H

class Remote;
class Tv
{
public:
    friend class Remote;
    enum {Off, On};
    enum {MinVal,MaxVal = 20};
    enum {Antenna, Cable};
    enum {TV, DVD};

    Tv(int s = Off, int mc = 125) : state(s), volume(5),
                                    maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void change_remote(Remote &r) const;
    void onoff() {state = (state == On)? Off : On;}
    bool ison() const {return state == On;}
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() {mode = (mode == Antenna)? Cable : Antenna;}
    void set_input() {input = (input == TV)? DVD : TV;}
    void settings() const; // display all settings
private:
    int state;             // on or off
    int volume;            // assumed to be digitized
    int maxchannel;        // maximum number of channels
    int channel;           // current channel setting
    int mode;              // broadcast or cable
    int input;             // TV or DVD
};

class Remote
{
private:
    int mode;              // controls TV or DVD
    int condition;         // normal or interact
public:
    enum {normal,interact};
    friend class Tv;
    Remote(int m = Tv::TV) : mode(m) { condition=0;}
    bool volup(Tv & t) { return t.volup();}
    bool voldown(Tv & t) { return t.voldown();}
    void onoff(Tv & t) { t.onoff(); }
    void chanup(Tv & t) {t.chanup();}
    void chandown(Tv & t) {t.chandown();}
    void set_chan(Tv & t, int c) {t.channel = c;}
    void set_mode(Tv & t) {t.set_mode();}
    void set_input(Tv & t) {t.set_input();}
    void show_con() const { std::cout<<(condition==normal?"Normal":"Interact")<<std::endl;}
};

inline void Tv::change_remote(Remote &r) const
{
    if(state==On)
        r.condition=(r.condition==Remote::normal?Remote::interact:Remote::normal);
}

#endif //EXERCISE01_TV_H
