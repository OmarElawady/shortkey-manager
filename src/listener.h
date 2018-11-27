#include <linux/input.h>
#include <string>
#include <X11/Xlib.h>

#ifndef M_LISTENER
#define M_LISTENER
class Listener{
  public:
    Listener();
    Listener(std::string kbd_file);
    // EFFECTS: waits until a key is pressed and returns the pressed key
    char retrieve();
  private:
    Display* dis;
};
#endif
