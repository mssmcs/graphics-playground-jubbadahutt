#include "graphics.h"

using namespace std;
using namespace mssm;

class Button {
public:
    Vec2d pos;
    Color color;
    int width;
    int height;
    string label;

    Button(Vec2d p, int w, int h, string l, Color c)
    {
        pos = p;
        width = w;
        height = h;
        label = l;
        color = c;
    }

    void draw(Graphics& g);
    bool isClicked(Graphics& g);
};

void Button::draw(Graphics& g)
{
    Color currentColor;

    g.rect({pos.x - width/2, pos.y - height/2}, width, height, currentColor);

    g.text(pos, 20, label, RED, HAlign::center);
}


bool Button::isClicked(Graphics &g)
{
    if (g.isMousePressed(MouseButton::Left)) {
        if (true) return true;
    }
    if (true) return false;
}

int main()
{
    Graphics g("THE BUTTON WILL EXIT THE TAB", 1024, 768);

    Button pressme({g.width()/2, g.height()/2}, 200, 100, "Press Me", RED);

    while (g.draw()) {
        pressme.draw(g);

            if (pressme.isClicked(g)) {
                break;
            }
    }
    return 0;
}

//if you click anywhere on the graphics box, the program will crash and kick you out of it. Essentially, the whole tab is just one big button.

