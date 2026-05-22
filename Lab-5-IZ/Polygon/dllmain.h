// dllmain.h: объявление класса модуля.

class CPolygonModule : public ATL::CAtlDllModuleT< CPolygonModule >
{
public :
	DECLARE_LIBID(LIBID_PolygonLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_POLYGON, "{81f97e0e-c4e2-4ce7-b42a-3fe8e6084bcf}")
};

extern class CPolygonModule _AtlModule;
