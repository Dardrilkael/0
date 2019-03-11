#include "Hammer/Input.h"

namespace Hammer {

class HM_API WindowsInput :public Input
{
private:


	// Herdado por meio de Input
	virtual bool IsKeyPressedImpl(int keycode) const override;

	virtual bool IsMouseButtonPressedImpl(int button) const override;

	virtual std::pair<float, float> GetMousePositionImpl() const override;

	virtual float GetMouseXPosImpl() const override;

	virtual float GetMousYPosImpl() const override;

};

}