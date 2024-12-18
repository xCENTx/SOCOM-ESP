#pragma once
#include <DXWindow/DXWindow.h>
#include <SDK/SOCOM.h>
#include <chrono>
#include <thread>
using namespace std::chrono_literals;

class Menu
{
public:
	void HUD();
	DxWindow::SOverlay GetOverlay();

public:
	explicit Menu();
	~Menu() noexcept = default;

private:
	DxWindow::SOverlay elements;
	void RenderCache();

}; inline std::unique_ptr<Menu> g_Menu;