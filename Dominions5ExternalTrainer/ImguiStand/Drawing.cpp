#include "Drawing.h"
//ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
LPCSTR Drawing::lpWindowName = "Dominions 5 External Trainer by RiritoXXL";
ImVec2 Drawing::vWindowSize = { 850, 850 };
ImGuiWindowFlags Drawing::WindowFlags = 0;
bool Drawing::bDraw = true;

void Drawing::Active()
{
	bDraw = true;
}

bool Drawing::isActive()
{
	return bDraw == true;
}

void Drawing::Draw()
{
	if (isActive())
	{
		ImGui::SetNextWindowSize(vWindowSize, ImGuiCond_Once);
		ImGui::SetNextWindowBgAlpha(1.0f);
		ImGui::Begin(lpWindowName, &bDraw, WindowFlags);
		{
			ImGui::Text("Create your own menu.");
			if (ImGui::Button("Player 3 Get Player Perl")) {
				Dom5::Player3_GetWaterPerl();
			}
		}
		ImGui::End();
	}

	#ifdef _WINDLL
	if (GetAsyncKeyState(VK_INSERT) & 1)
		bDraw = !bDraw;
	#endif
}
