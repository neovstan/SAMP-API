#pragma once

#include "sampapi/sampapi.h"
#include "sampapi/CVector.h"
#include "sampapi/CMatrix.h"
#include <windows.h>

SAMPAPI_BEGIN_PACKED_V037R3_1

struct ID3DXLine;

enum ObjectEditType
{
  kNone = 0x0,
  kAttachedObject = 0x2,
  kObject = 0x1,
};

enum ObjectEditMode
{
  kPosition = 0x0,
  kRotation = 0x1,
  kScale = 0x2,
};

enum ObjectEditProcessType
{
  kXAxis = 0x0,
  kYAxis = 0x1,
  kZAxis = 0x2,
  kSetPosition = 0x3,
  kSetRotation = 0x4,
  kSetScale = 0x5,
  kSave = 0xA,
};

class CObjectEdit
{
public:
  POINT m_CharMaxSize;
  RECT m_xAxisButtonRect;
  RECT m_yAxisButtonRect;
  RECT m_zAxisButtonRect;
  RECT m_PositionButtonRect;
  RECT m_RotationButtonRect;
  RECT m_ScaleButtonRect;
  RECT m_SaveButtonRect;
  int m_nEditType;
  int m_nEditMode;
  BOOL m_bEnabled;
  BOOL m_bRenderedThisFrame;
  sampapi::ID m_nEditObjectId;
  unsigned int m_nAttachedObjectIndex;
  BOOL m_bIsPlayerObject;
  sampapi::CVector rotation;
  unsigned int m_nLastSentNotificationTick;
  bool m_bRenderScaleButton;
  bool m_bEditingRightNow;
  bool m_bTopXOfObjectIsOnLeftOfScreen;
  bool m_bTopYOfObjectIsOnLeftOfScreen;
  bool m_bTopZOfObjectIsOnLeftOfScreen;
  POINT m_EditStartPos;
  POINT m_CursorPosInGame;
  BOOL m_bObjectXSizeYCoordDiffMoreThanX;
  BOOL m_bObjectYSizeYCoordDiffMoreThanX;
  BOOL m_bObjectZSizeYCoordDiffMoreThanX;
  sampapi::CMatrix m_entityMatrix;
  IDirect3DDevice9 *m_pDevice;
  ID3DXLine *m_pLine;
  ID3DXFont *m_pIconFontSmall;
  ID3DXFont *m_pIconFontBig;
  int m_nProcessType;

  CObjectEdit(IDirect3DDevice9 *RefDevice);
  float WorldToScreen(sampapi::CVector *in, float(&out)[2]);
  float WorldToScreen(sampapi::CVector *in, float*);
  int RenderAxes(sampapi::CMatrix *a2, float linesize);
  const char* GetRenderChar(BOOL for_big_font);
  void TryChangeProcessType();
  void SetEditMode(ObjectEditMode mode);
  void ResetMousePos();
  void EnterEditObject(sampapi::ID object_id, BOOL player_object);
  void SendEditEndNotification(int response);
  void SendAttachedEditEndNotification(int response);
  void Disable(BOOL result);
  BOOL RenderControlsForObject(sampapi::CMatrix* object_matrix, float linesize);
  void ApplyChanges(ObjectEditProcessType type, float diff);
  void ProcessMouseMove();
  BOOL MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
  void Render();


  static const char* GetMaxSizeChar();
};

CObjectEdit*& RefObjectEdit(VersionTag = {});

SAMPAPI_END_PACKED