// https://github.com/NightFyre/DX11-ImGui-External-Base/tree/main

#pragma once
#include <vector>
#include <memory>
#include <functional>

//	DirectX
#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")

//  ImGui
#define IMGUI_DEFINE_MATH_OPERATORS 1
#include <imgui.h>
#include <imgui_internal.h>
#include <backends/imgui_impl_win32.h>
#include <backends/imgui_impl_dx11.h>

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

class DxWindow
{
public:
	typedef std::function<void()> OverlayFunctionPtr;
	struct SOverlay
	{
		OverlayFunctionPtr Hud;
	};

public:
	ImVec2 GetScreenSize();
	HWND GetWindowHandle();
	ID3D11Device* GetD3DDevice();
	IDXGISwapChain* GetSwapChain();
	ID3D11DeviceContext* GetDeviceContext();
	ID3D11RenderTargetView* GetRTV();

public:
	void Update(SOverlay bind);

public:
	explicit DxWindow();
	~DxWindow();

private:
	HWND m_hwnd{ 0 };
	WNDCLASSEX m_wc{ };
	ID3D11Device* m_pd3dDevice{ nullptr };
	IDXGISwapChain* m_pSwapChain{ nullptr };
	ID3D11DeviceContext* m_pd3dDeviceContext{ nullptr };
	ID3D11RenderTargetView* m_mainRenderTargetView{ nullptr };
	ImVec2 m_szScreen{ 0.0f, 0.0f };

private:
	bool CreateDeviceD3D(HWND hWnd);
	void CleanupDeviceD3D();
	void CreateRenderTarget();
	void CleanupRenderTarget();

private:
	static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
}; inline std::unique_ptr<DxWindow> g_dxWindow;