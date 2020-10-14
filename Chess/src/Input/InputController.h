#ifndef INPUT_INPUTCONTROLLER_H_
#define INPUT_INPUTCONTROLLER_H_

#include <functional>
#include <Board.h>

class InputController
{
public:
	void Update(Board& chessBoard);
	void Init( std::function<void()> );
private:
	std::function<void()> mQuit;
};


#endif /* INPUT_INPUTCONTROLLER_H_ */
