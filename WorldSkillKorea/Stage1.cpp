#include "Stage1.h"

Stage1::Stage1(ID3D11Device* device) :
	m_Background(nullptr),
	m_BackgroundTexture(nullptr),
	m_Submarine(nullptr),
	m_SubmarineTexture(nullptr),
	m_View(nullptr)
{
	m_BackgroundTexture = new Texture(device, "./res/Background/Stage1.dds");
	m_Background = new Background(device, m_BackgroundTexture);
	
	m_SubmarineTexture = new Texture(device, "./res/Player/Submarine.dds");
	m_Submarine = new Submarine(device, m_SubmarineTexture);

	m_View = new View();
}

Stage1::~Stage1()
{
	delete m_Background;
	delete m_BackgroundTexture;
	delete m_Submarine;
	delete m_SubmarineTexture;
	delete m_View;
}

void Stage1::update(float deltaTime)
{
	m_Background->update(deltaTime);
	m_Submarine->update(deltaTime);
}

void Stage1::draw(ID3D11DeviceContext* deviceContext, CXMMATRIX ortho)
{
	XMMATRIX viewOrtho = m_View->getViewMatrix() * ortho;

	m_Background->draw(deviceContext, viewOrtho);
	m_Submarine->draw(deviceContext, viewOrtho);
}