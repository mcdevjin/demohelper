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
#include <windows.h>
#include <vector>

enum class ColorButtonDialogResult
{
    None,
    Cancel,
    Ok
};

class CColorButton
{
public:
    CColorButton();
    virtual ~CColorButton();

    BOOL ConvertToColorButton(HWND hwndParent, UINT uiCtlId);

    void SetColor(COLORREF clr);
    COLORREF GetColor() const { return m_color; }
    COLORREF GetLastColor() const { return m_lastColor; }
    ColorButtonDialogResult GetDialogResult() const { return m_dialogResult; }
    void Reset()
    {
        m_hasLastColor = false;
    }

protected:

private:
    WNDPROC     m_pfnOrigCtlProc = nullptr;
    COLORREF    m_color = 0;
    HWND        m_hwnd = nullptr;
    UINT        m_ctlId = 0;
    bool        m_hasLastColor = false;
    COLORREF    m_lastColor = 0;
    std::vector<HWND> m_colorEdits;
    ColorButtonDialogResult m_dialogResult = ColorButtonDialogResult::None;

private:
    bool ConvertToColorButton(HWND hwndCtl);
    inline static CColorButton* GetObjectFromWindow(HWND hWnd)
    {
        return reinterpret_cast<CColorButton *>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
    }
    static LRESULT CALLBACK _ColorButtonProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
    static UINT_PTR CALLBACK CCHookProc(
        _In_ HWND   hdlg,
        _In_ UINT   uiMsg,
        _In_ WPARAM wParam,
        _In_ LPARAM lParam
        );
};
