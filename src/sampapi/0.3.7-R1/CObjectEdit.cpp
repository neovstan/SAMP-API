#include "sampapi/0.3.7-R1/CObjectEdit.h"

SAMPAPI_BEGIN_V037R1

CObjectEdit*& RefObjectEdit(VersionTag) {
  return *reinterpret_cast<CObjectEdit**>(sampapi::GetAddress(0x21A0C4));
}

CObjectEdit::CObjectEdit(IDirect3DDevice9* RefDevice) {
  reinterpret_cast<CObjectEdit*(__thiscall*)(CObjectEdit*, IDirect3DDevice9*)>(sampapi::GetAddress(0x6D580))(this, RefDevice);
}

float CObjectEdit::WorldToScreen(sampapi::CVector* in, float (&out)[2]) {
  return reinterpret_cast<float(__thiscall*)(CObjectEdit*, sampapi::CVector*, float*)>(sampapi::GetAddress(0x6D640))(this, in, out);
}

float CObjectEdit::WorldToScreen(sampapi::CVector* in, float* out) {
  return reinterpret_cast<float(__thiscall*)(CObjectEdit*, sampapi::CVector*, float*)>(sampapi::GetAddress(0x6D640))(this, in, out);
}

int CObjectEdit::RenderAxes(sampapi::CMatrix* a2, float linesize) {
  return reinterpret_cast<int(__thiscall*)(CObjectEdit*, sampapi::CMatrix*, float)>(sampapi::GetAddress(0x6D740))(this, a2, linesize);
}

const char* CObjectEdit::GetRenderChar(BOOL for_big_font) {
  return reinterpret_cast<const char*(__thiscall*)(CObjectEdit*, BOOL)>(sampapi::GetAddress(0x6D9C0))(this, for_big_font);
}

void CObjectEdit::TryChangeProcessType() {
  reinterpret_cast<void(__thiscall*)(CObjectEdit*)>(sampapi::GetAddress(0x6DAC0))(this);
}

void CObjectEdit::SetEditMode(ObjectEditMode mode) {
  reinterpret_cast<void(__thiscall*)(CObjectEdit*, ObjectEditMode)>(sampapi::GetAddress(0x6DC10))(this, mode);
}

void CObjectEdit::ResetMousePos() {
  reinterpret_cast<void(__thiscall*)(CObjectEdit*)>(sampapi::GetAddress(0x6DDE0))(this);
}

void CObjectEdit::EnterEditObject(sampapi::ID object_id, BOOL player_object) {
  reinterpret_cast<void
(__thiscall*)(CObjectEdit*, sampapi::ID, BOOL)>(sampapi::GetAddress(0x6DE40))(this, object_id, player_object);
}

void CObjectEdit::SendEditEndNotification(int response) {
  reinterpret_cast<void(__thiscall*)(CObjectEdit*, int)>(sampapi::GetAddress(0x6E2D0))(this, response);
}

void CObjectEdit::SendAttachedEditEndNotification(int response) {
  reinterpret_cast<void(__thiscall*)(CObjectEdit*, int)>(sampapi::GetAddress(0x6E4E0))(this, response);
}

void CObjectEdit::Disable(BOOL result) {
  reinterpret_cast<void(__thiscall*)(CObjectEdit*, BOOL)>(sampapi::GetAddress(0x6E5E0))(this, result);
}

BOOL CObjectEdit::RenderControlsForObject(sampapi::CMatrix* object_matrix, float linesize) {
  return reinterpret_cast<BOOL(__thiscall*)(CObjectEdit*, sampapi::CMatrix*, float)>(sampapi::GetAddress(0x6E650))(this, object_matrix, linesize);
}

void CObjectEdit::ApplyChanges(ObjectEditProcessType type, float diff) {
  reinterpret_cast<void(__thiscall*)(CObjectEdit*, ObjectEditProcessType, float)>(sampapi::GetAddress(0x6EE80))(this, type, diff);
}

void CObjectEdit::ProcessMouseMove() {
  //reinterpret_cast<float(__thiscall*)(CObjectEdit*)>(sampapi::GetAddress(0x72D90))(this);
}

BOOL CObjectEdit::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam) {
  return reinterpret_cast<BOOL(__thiscall*)(CObjectEdit*, UINT, WPARAM, LPARAM)>(sampapi::GetAddress(0x6EF70))(this, uMsg, wParam, lParam);
}

void CObjectEdit::Render() {
  reinterpret_cast<void(__thiscall*)(CObjectEdit*)>(sampapi::GetAddress(0x6F1A0))(this);
}

const char* CObjectEdit::GetMaxSizeChar() {
  return reinterpret_cast<const char*(__cdecl*)()>(sampapi::GetAddress(0x6D9B0))();
}

SAMPAPI_END