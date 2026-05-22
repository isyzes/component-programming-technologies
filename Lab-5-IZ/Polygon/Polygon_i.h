

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Tue Jan 19 06:14:07 2038
 */
/* Compiler settings for Polygon.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0628 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Polygon_i_h__
#define __Polygon_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IPolyCtl_FWD_DEFINED__
#define __IPolyCtl_FWD_DEFINED__
typedef interface IPolyCtl IPolyCtl;

#endif 	/* __IPolyCtl_FWD_DEFINED__ */


#ifndef ___IPolyCtlEvents_FWD_DEFINED__
#define ___IPolyCtlEvents_FWD_DEFINED__
typedef interface _IPolyCtlEvents _IPolyCtlEvents;

#endif 	/* ___IPolyCtlEvents_FWD_DEFINED__ */


#ifndef __PolyCtl_FWD_DEFINED__
#define __PolyCtl_FWD_DEFINED__

#ifdef __cplusplus
typedef class PolyCtl PolyCtl;
#else
typedef struct PolyCtl PolyCtl;
#endif /* __cplusplus */

#endif 	/* __PolyCtl_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IPolyCtl_INTERFACE_DEFINED__
#define __IPolyCtl_INTERFACE_DEFINED__

/* interface IPolyCtl */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IPolyCtl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7a091d01-6d0e-484b-a73c-fc4df15144be")
    IPolyCtl : public IDispatch
    {
    public:
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_BorderColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_BorderColor( 
            /* [retval][out] */ OLE_COLOR *pclr) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_FillColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_FillColor( 
            /* [retval][out] */ OLE_COLOR *pclr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Sides( 
            /* [retval][out] */ SHORT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Sides( 
            /* [in] */ SHORT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GraphColor( 
            /* [retval][out] */ OLE_COLOR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_GraphColor( 
            /* [in] */ OLE_COLOR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BackgroundColor( 
            /* [retval][out] */ OLE_COLOR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BackgroundColor( 
            /* [in] */ OLE_COLOR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_XMin( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_XMin( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_XMax( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_XMax( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_YMin( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_YMin( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_YMax( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_YMax( 
            /* [in] */ DOUBLE newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPolyCtlVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPolyCtl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPolyCtl * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPolyCtl * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPolyCtl * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPolyCtl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPolyCtl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPolyCtl * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IPolyCtl, put_BorderColor)
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BorderColor )( 
            IPolyCtl * This,
            /* [in] */ OLE_COLOR clr);
        
        DECLSPEC_XFGVIRT(IPolyCtl, get_BorderColor)
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BorderColor )( 
            IPolyCtl * This,
            /* [retval][out] */ OLE_COLOR *pclr);
        
        DECLSPEC_XFGVIRT(IPolyCtl, put_FillColor)
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FillColor )( 
            IPolyCtl * This,
            /* [in] */ OLE_COLOR clr);
        
        DECLSPEC_XFGVIRT(IPolyCtl, get_FillColor)
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FillColor )( 
            IPolyCtl * This,
            /* [retval][out] */ OLE_COLOR *pclr);
        
        DECLSPEC_XFGVIRT(IPolyCtl, get_Sides)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Sides )( 
            IPolyCtl * This,
            /* [retval][out] */ SHORT *pVal);
        
        DECLSPEC_XFGVIRT(IPolyCtl, put_Sides)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Sides )( 
            IPolyCtl * This,
            /* [in] */ SHORT newVal);
        
        DECLSPEC_XFGVIRT(IPolyCtl, get_GraphColor)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_GraphColor )( 
            IPolyCtl * This,
            /* [retval][out] */ OLE_COLOR *pVal);
        
        DECLSPEC_XFGVIRT(IPolyCtl, put_GraphColor)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_GraphColor )( 
            IPolyCtl * This,
            /* [in] */ OLE_COLOR newVal);
        
        DECLSPEC_XFGVIRT(IPolyCtl, get_BackgroundColor)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BackgroundColor )( 
            IPolyCtl * This,
            /* [retval][out] */ OLE_COLOR *pVal);
        
        DECLSPEC_XFGVIRT(IPolyCtl, put_BackgroundColor)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BackgroundColor )( 
            IPolyCtl * This,
            /* [in] */ OLE_COLOR newVal);
        
        DECLSPEC_XFGVIRT(IPolyCtl, get_XMin)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XMin )( 
            IPolyCtl * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        DECLSPEC_XFGVIRT(IPolyCtl, put_XMin)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_XMin )( 
            IPolyCtl * This,
            /* [in] */ DOUBLE newVal);
        
        DECLSPEC_XFGVIRT(IPolyCtl, get_XMax)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XMax )( 
            IPolyCtl * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        DECLSPEC_XFGVIRT(IPolyCtl, put_XMax)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_XMax )( 
            IPolyCtl * This,
            /* [in] */ DOUBLE newVal);
        
        DECLSPEC_XFGVIRT(IPolyCtl, get_YMin)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_YMin )( 
            IPolyCtl * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        DECLSPEC_XFGVIRT(IPolyCtl, put_YMin)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_YMin )( 
            IPolyCtl * This,
            /* [in] */ DOUBLE newVal);
        
        DECLSPEC_XFGVIRT(IPolyCtl, get_YMax)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_YMax )( 
            IPolyCtl * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        DECLSPEC_XFGVIRT(IPolyCtl, put_YMax)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_YMax )( 
            IPolyCtl * This,
            /* [in] */ DOUBLE newVal);
        
        END_INTERFACE
    } IPolyCtlVtbl;

    interface IPolyCtl
    {
        CONST_VTBL struct IPolyCtlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPolyCtl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPolyCtl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPolyCtl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPolyCtl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPolyCtl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPolyCtl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPolyCtl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IPolyCtl_put_BorderColor(This,clr)	\
    ( (This)->lpVtbl -> put_BorderColor(This,clr) ) 

#define IPolyCtl_get_BorderColor(This,pclr)	\
    ( (This)->lpVtbl -> get_BorderColor(This,pclr) ) 

#define IPolyCtl_put_FillColor(This,clr)	\
    ( (This)->lpVtbl -> put_FillColor(This,clr) ) 

#define IPolyCtl_get_FillColor(This,pclr)	\
    ( (This)->lpVtbl -> get_FillColor(This,pclr) ) 

#define IPolyCtl_get_Sides(This,pVal)	\
    ( (This)->lpVtbl -> get_Sides(This,pVal) ) 

#define IPolyCtl_put_Sides(This,newVal)	\
    ( (This)->lpVtbl -> put_Sides(This,newVal) ) 

#define IPolyCtl_get_GraphColor(This,pVal)	\
    ( (This)->lpVtbl -> get_GraphColor(This,pVal) ) 

#define IPolyCtl_put_GraphColor(This,newVal)	\
    ( (This)->lpVtbl -> put_GraphColor(This,newVal) ) 

#define IPolyCtl_get_BackgroundColor(This,pVal)	\
    ( (This)->lpVtbl -> get_BackgroundColor(This,pVal) ) 

#define IPolyCtl_put_BackgroundColor(This,newVal)	\
    ( (This)->lpVtbl -> put_BackgroundColor(This,newVal) ) 

#define IPolyCtl_get_XMin(This,pVal)	\
    ( (This)->lpVtbl -> get_XMin(This,pVal) ) 

#define IPolyCtl_put_XMin(This,newVal)	\
    ( (This)->lpVtbl -> put_XMin(This,newVal) ) 

#define IPolyCtl_get_XMax(This,pVal)	\
    ( (This)->lpVtbl -> get_XMax(This,pVal) ) 

#define IPolyCtl_put_XMax(This,newVal)	\
    ( (This)->lpVtbl -> put_XMax(This,newVal) ) 

#define IPolyCtl_get_YMin(This,pVal)	\
    ( (This)->lpVtbl -> get_YMin(This,pVal) ) 

#define IPolyCtl_put_YMin(This,newVal)	\
    ( (This)->lpVtbl -> put_YMin(This,newVal) ) 

#define IPolyCtl_get_YMax(This,pVal)	\
    ( (This)->lpVtbl -> get_YMax(This,pVal) ) 

#define IPolyCtl_put_YMax(This,newVal)	\
    ( (This)->lpVtbl -> put_YMax(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPolyCtl_INTERFACE_DEFINED__ */



#ifndef __PolygonLib_LIBRARY_DEFINED__
#define __PolygonLib_LIBRARY_DEFINED__

/* library PolygonLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_PolygonLib;

#ifndef ___IPolyCtlEvents_DISPINTERFACE_DEFINED__
#define ___IPolyCtlEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IPolyCtlEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__IPolyCtlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("46c3617e-b7bd-4f87-87c3-6d4cf57aaf1a")
    _IPolyCtlEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IPolyCtlEventsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IPolyCtlEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IPolyCtlEvents * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IPolyCtlEvents * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IPolyCtlEvents * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IPolyCtlEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IPolyCtlEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IPolyCtlEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _IPolyCtlEventsVtbl;

    interface _IPolyCtlEvents
    {
        CONST_VTBL struct _IPolyCtlEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IPolyCtlEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IPolyCtlEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IPolyCtlEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IPolyCtlEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IPolyCtlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IPolyCtlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IPolyCtlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IPolyCtlEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_PolyCtl;

#ifdef __cplusplus

class DECLSPEC_UUID("2205e542-da76-4e54-89d9-9564966cca4b")
PolyCtl;
#endif
#endif /* __PolygonLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


