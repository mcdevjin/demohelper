﻿// demoHelper - screen drawing and presentation tool

// Copyright (C) 2020 - Stefan Kueng

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
#pragma once
#include "BaseWindow.h"
#include "DPIAware.h"
#include "AnimationManager.h"
#include <string>
#include <vector>

class CMouseOverlayWnd : public CWindow
{
public:
    CMouseOverlayWnd(HINSTANCE hInst, const WNDCLASSEX* wcx = NULL)
        : CWindow(hInst, wcx)
        , m_color(0)
    {
        RegisterAndCreateWindow();
    }
    ~CMouseOverlayWnd(void);

    void Show(POINT screenPos, COLORREF color, double fadeTo);
    void UpdatePos(POINT screenPos);
    void Fade();

private:
protected:
    virtual void OnPaint(HDC hDC, LPRECT pRect);
    /**
     * Registers the window class and creates the window.
     */
    bool RegisterAndCreateWindow();
    /// the message handler for this window
    LRESULT CALLBACK WinMsgHandler(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
    IUIAnimationVariablePtr m_AnimVar;
    COLORREF                m_color;
};
