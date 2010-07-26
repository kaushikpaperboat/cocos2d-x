/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef __COCOA_NS_MUTATLE_ARRAY_H__
#define __COCOA_NS_MUTATLE_ARRAY_H__

#include "cocoa/NSObject.h"
#include "platform/Cocos2dTypes.h"
#include <vector>

template<class T = NSObject*>
class NSMutableArray : public NSObject
{
public:
	typedef std::vector<T>								NSObjectArray;
	typedef typename NSObjectArray::iterator			NSMutableArrayIterator;
	typedef typename NSObjectArray::reverse_iterator	NSMutableArrayRevIterator;

public:
	NSMutableArray(UINT32 uSize = 0);
    ~NSMutableArray(void);
	UINT32 count(void);

	UINT32 getIndexOfObject(T pObject);
	bool containsObject(T pObject);
	T getLastObject(void);
	T getObjectAtIndex(UINT32 uIndex);

	// Adding objects
	void addObject(T pObject);
	void addObjectsFromArray(NSMutableArray<T> *pArray);
    void insertObjectAtIndex(T pObject, UINT32 uIndex);

	// Removing objects
	void removeLastObject(void);
	void removeObject(T pObject);
	void removeObjectAtIndex(UINT32 uIndex);
	void removeAllObjects(void);
	void replaceObjectAtIndex(UINT32 uIndex, T pObject);

	NSMutableArrayIterator begin(void);
	NSMutableArrayIterator end(void);

public:
	static NSMutableArray<T>* arrayWithObjects(T pObject1, ...);
	static NSMutableArray<T>* arrayWithArray(NSMutableArray<T> *pArray);

private:
	std::vector<T> m_array;
};

#define NSArray NSMutableArray

#endif // __COCOA_NS_MUTATLE_ARRAY_H__
