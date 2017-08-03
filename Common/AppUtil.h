#ifndef _APP_UTIL_H_
#define _APP_UTIL_H_

#include <Windows.h>
#include <xnamath.h>






#ifndef HR
#define HR(x)    { hr = x; if( FAILED(hr) ) { return hr; } }         //�Զ���һ��HR�꣬����ִ�д���ķ���
#endif

#ifndef SAFE_DELETE					
#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }       //�Զ���һ��SAFE_RELEASE()��,����ָ����Դ���ͷ�
#endif    

#ifndef SAFE_RELEASE			
#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }     //�Զ���һ��SAFE_RELEASE()��,����COM��Դ���ͷ�
#endif
inline int KeyDown(char vKey)
{
	return GetAsyncKeyState(vKey) & 0x8000;
}

namespace Colors
{
	//���弸����������ɫֵ�������ڳ�����ʹ��
	const XMVECTORF32 White     = {1.0f, 1.0f, 1.0f, 1.0f};
	const XMVECTORF32 Black     = {0.0f, 0.0f, 0.0f, 1.0f};
	const XMVECTORF32 Red       = {1.0f, 0.0f, 0.0f, 1.0f};
	const XMVECTORF32 Green     = {0.0f, 1.0f, 0.0f, 1.0f};
	const XMVECTORF32 Blue      = {0.0f, 0.0f, 1.0f, 1.0f};
	const XMVECTORF32 Yellow    = {1.0f, 1.0f, 0.0f, 1.0f};
	const XMVECTORF32 Cyan      = {0.0f, 1.0f, 1.0f, 1.0f};
	const XMVECTORF32 Magenta   = {1.0f, 0.0f, 1.0f, 1.0f};
	const XMVECTORF32 Silver	= {0.75f,0.75f,0.75f,1.0f};
};


#endif