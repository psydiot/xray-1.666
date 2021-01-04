////////////////////////////////////////////////////////////////////////////
// Module : ai_script_lua_extension.h
// Created : 19.09.2003
// Modified : 22.09.2003
// Author : Dmitriy Iassenev
// Description : XRay Script extensions
////////////////////////////////////////////////////////////////////////////

#pragma once

//struct CLuaVirtualMachine;

namespace Script
{
#ifndef ENGINE_BUILD
void vfExportGlobals(lua_State* tpLuaVM);
void vfExportFvector(lua_State* tpLuaVM);
void vfExportFmatrix(lua_State* tpLuaVM);
void vfExportGame(lua_State* tpLuaVM);
void vfExportLevel(lua_State* tpLuaVM);
void vfExportDevice(lua_State* tpLuaVM);
void vfExportParticles(lua_State* tpLuaVM);
void vfExportSound(lua_State* tpLuaVM);
void vfExportHit(lua_State* tpLuaVM);
void vfExportActions(lua_State* tpLuaVM);
void vfExportObject(lua_State* tpLuaVM);
void vfExportEffector(lua_State* tpLuaVM);
void vfExportArtifactMerger(lua_State* tpLuaVM);
void vfLoadStandardScripts(lua_State* tpLuaVM);
void vfExportMemoryObjects(lua_State* tpLuaVM);
void vfExportToLua(lua_State* tpLuaVM);
void vfExportActionManagement(lua_State* tpLuaVM);
void vfExportMotivationManagement(lua_State* tpLuaVM);
bool bfLoadFile(lua_State* tpLuaVM, LPCSTR caScriptName, bool bCall = true);
void LuaHookCall(lua_State* tpLuaVM,struct lua_Debug* tpLuaDebug);
int LuaPanic(lua_State* tpLuaVM);
#endif
bool bfPrintOutput(lua_State* tpLuaVM, LPCSTR caScriptName, int iErorCode = 0);
LPCSTR cafEventToString(int iEventCode);
void vfPrintError(lua_State* tpLuaVM, int iErrorCode);
bool bfListLevelVars(lua_State* tpLuaVM, int iStackLevel);
bool bfLoadBuffer(lua_State* tpLuaVM, LPCSTR caBuffer, size_t tSize, LPCSTR caScriptName, LPCSTR caNameSpaceName = 0);
bool bfLoadFileIntoNamespace(lua_State* tpLuaVM, LPCSTR caScriptName, LPCSTR caNamespaceName, bool bCall);
bool bfGetNamespaceTable(lua_State* tpLuaVM, LPCSTR caName);
lua_State* get_namespace_table(lua_State* tpLuaVM, LPCSTR caName);
bool bfIsObjectPresent(lua_State* tpLuaVM, LPCSTR caIdentifier, int type);
bool bfIsObjectPresent(lua_State* tpLuaVM, LPCSTR caNamespaceName, LPCSTR caIdentifier, int type);
//luabind::luabind::object lua_namespace_table(lua_State* tpLuaVM, LPCSTR namespace_name);
};
