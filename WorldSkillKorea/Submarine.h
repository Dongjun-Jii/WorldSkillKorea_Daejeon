#pragma once
#include "GameObject.h"

class Submarine : public GameObject
{
public:
	Submarine() = delete;
	Submarine(Submarine&) = delete;
	Submarine(ID3D11Device* device, Texture* normalTexture, Texture* movingTexture);
	virtual ~Submarine() = default;

	virtual void update(float deltaTime) override;

	virtual XMFLOAT3 getPosition() const override;

	void onHitted() {
		m_Life -= 1;
		if (m_Life == 0)
		{
			throw "Died!";
		}
	}
private:
	static const int SPEED = 1000;
	Texture* m_MovingTexture;
	Texture* m_NormalTexture;
	int m_Life;
};