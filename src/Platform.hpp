#pragma once

struct platform{
    int x, y, length;
    platform *next;
};
typedef platform *p_plat;

class Platform{
    private:
        p_plat plat;
    public:
        Platform();
        p_plat create_platform(int x, int y, int length, p_plat plat);
        bool checkPlatform(int player_x, int player_y);
};