// dllmain.h: объявление класса модуля.

class CAutoSvrModule : public ATL::CAtlDllModuleT< CAutoSvrModule >
{
public :
	DECLARE_LIBID(LIBID_AutoSvrLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_AUTOSVR, "{c85b3ba9-da8a-450f-9000-122541b181cb}")
};

extern class CAutoSvrModule _AtlModule;
