#ifndef __INPUT_HANDLER__
#define __INPUT_HANDLER__

#include <SDL2/SDL.h>
#include <vector>
#include "Vector2D.h"

using namespace std;

const int m_joystickDeadZone = 10000;

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if(s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}

	void initialiseJoysticks();
	bool joysticksInitialised() { return m_bJoysticksInitialised; }

	int xvalue(int joy, int stick);
	int yvalue(int joy, int stick);

	void update();
	void clean();

private:
	InputHandler(){}
	~InputHandler() {}

	static InputHandler* s_pInstance;

	std::vector<SDL_Joystick*> m_joysticks;
	std::vector<std::pair<Vector2D*, Vector2D*> > m_joystickValues;
	bool m_bJoysticksInitialised;
};

typedef InputHandler TheInputHandler;

#endif