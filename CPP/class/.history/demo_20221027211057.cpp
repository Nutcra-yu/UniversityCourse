/*
Author: wuqiang
Email:	debugroot@126.com
Description:exstring is a subclass of basic_string.It is added some userful
operations,such as toUpper,toLower,toNumber,fromNumber,format,etc.It can also
convert between basic_string seamlessly,which is very important for compatibility.
And it is almostly a wrapper of some C++ standard library,so there should be no bugs.
If you find some,please let me known.It is totally free,you can use it in any way you desire.
*/
#pragma once

#include <string>
#include <stdarg.h>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

#ifndef INLINE
#define INLINE inline
#endif // INLINE

static ios_base::fmtflags BaseFlag(int base)
{
    return (base == 16) ? (ios_base::hex) : ((base == 8) ? (ios_base::oct) : (ios_base::dec));
}

template <class _Elem>
struct ex_char_traits
{
};

template <>
struct ex_char_traits<char>
{
    static INLINE int ct_vscprintf(const char *format, va_list argptr)
    {
        return _vscprintf(format, argptr);
    }
    static INLINE int ct_vstprintf_s(char *buffer, size_t numberOfElements,
                                     const char *format, va_list argptr)
    {
        return vsprintf_s(buffer, numberOfElements, format, argptr);
    }
};

template <>
struct ex_char_traits<wchar_t>
{
    static INLINE int ct_vscprintf(const wchar_t *format, va_list argptr)
    {
        return _vscwprintf(format, argptr);
    }
    static INLINE int ct_vstprintf_s(wchar_t *buffer, size_t numberOfElements,
                                     const wchar_t *format, va_list argptr)
    {
        return vswprintf_s(buffer, numberOfElements, format, argptr);
    }
};

template <class _Elem, class _Traits, class _Ax, class Type>
Type ConvertToNumber(basic_stringstream<_Elem, _Traits, _Ax> &ss,
                     Type t, int base)
{
    ss.setf(BaseFlag(base), ios_base::basefield);
    ss >> t;
    return t;
}

template <class _Elem, class _Traits, class _Ax>
float ConvertToNumber(basic_stringstream<_Elem, _Traits, _Ax> &ss,
                      float t, int /*ignore base*/)
{
    ss >> t;
    return t;
}

template <class _Elem, class _Traits, class _Ax>
double ConvertToNumber(basic_stringstream<_Elem, _Traits, _Ax> &ss,
                       double t, int /*ignore base*/)
{
    ss >> t;
    return t;
}

template <class _Elem, class _Traits, class _Ax, class _ExTraits>
class basic_exstring : public basic_string<_Elem, _Traits, _Ax>
{
public:
    typedef basic_exstring<_Elem, _Traits, _Ax, _ExTraits> _Myt;
    typedef basic_string<_Elem, _Traits, _Ax> _Mybase;

#pragma region "constructor"

    //���й��캯������Ϊͬbasic_string

    explicit INLINE _Myt(const _Ax &al = _Ax())
        : _Mybase(al)
    {
    }
    INLINE _Myt(const _Myt &rhs)
        : _Mybase(rhs)
    {
    }
    INLINE _Myt(const _Myt &rhs, size_type pos, size_type n, const _Ax &al = _Ax())
        : _Mybase(rhs, pos, n, al)
    {
    }
    INLINE _Myt(const _Elem *s, size_type n, const _Ax &al = _Ax())
        : _Mybase(s, n, al)
    {
    }
    INLINE _Myt(const _Elem *s, const _Ax &al = _Ax())
        : _Mybase(s, al)
    {
    }
    INLINE _Myt(size_type n, _Elem c, const _Ax &al = _Ax())
        : _Mybase(n, c, al)
    {
    }
    INLINE _Myt(const_iterator first, const_iterator last, const _Ax &al = _Ax())
        : _Mybase(first, last, al)
    {
    }

    // string(wstring)ת��Ϊexstring(exwstring)
    INLINE _Myt(const _Mybase &base)
        : _Mybase(base)
    {
    }
#pragma endregion // constructor

#pragma region "general operation"

    //�����ַ�תΪ��д���ı�����
    _Myt &toUpper()
    {
        transform(begin(), end(), begin(), toupper);
        return *this;
    }

    //�����ַ�תΪ��д�����ı�����
    _Myt toUpper() const
    {
        _Myt s;
        transform(begin(), end(), s.begin(), toupper);
        return s;
    }

    //�����ַ�תΪСд���ı�����
    _Myt &toLower()
    {
        transform(begin(), end(), begin(), tolower);
        return *this;
    }

    //�����ַ�תΪ��д�����ı�����
    _Myt toLower() const
    {
        _Myt s(_Mysize, _Elem());
        transform(begin(), end(), s.begin(), tolower);
        return s;
    }

    //������oldStr�滻ΪnewStr
    _Myt &replace(const _Myt &oldStr, const _Myt &newStr)
    {
        if (oldStr.empty())
            return *this;
        size_type index;
        while ((index = find(oldStr)) != npos)
            _Mybase::replace(index, oldStr.size(), newStr);
        return *this;
    }

    //ɾ��������а�����target�е��ַ�
    _Myt &trimLeft(const _Myt &target)
    {
        while (!empty() && (target.find(*begin()) != npos))
            erase(begin());
        return *this;
    }

    //ɾ���ұ����а�����target�е��ַ�
    _Myt &trimRight(const _Myt &target)
    {
        while (!empty() && target.find(*rbegin()) != npos)
            erase(--end());
        return *this;
    }

    //�������count���ַ���count�����ܳ����򷵻������ַ���
    _Myt left(size_type count) const
    {
        return substr(0, count);
    }

    //�����ұ�count���ַ���count�����ܳ����򷵻������ַ���
    _Myt right(size_type count) const
    {
        return substr(_Mysize < count ? 0 : _Mysize - count);
    }

    //���Դ�Сд�ж������ַ����Ƿ����
    int compareNoCase(const _Myt &rhs) const
    {
        return toLower().compare(rhs.toLower());
    }

    //�ж��ַ����Ƿ����ƶ��ַ�����ͷ
    bool beginWith(const _Myt &rhs) const
    {
        return find(rhs) == size_type(0);
    }

    //�ж��ַ����Ƿ����ƶ��ַ�����β
    bool endWith(const _Myt &rhs) const
    {
        if (rhs.size() > _Mysize)
            return false;
        return compare(_Mysize - rhs.size(), rhs.size(), rhs) == 0;
    }
#pragma endregion // general operation

#pragma region "convert between numbers"

    //���ַ���תΪ����
    // base:������������Ϊ8,10,16���������ֵ��ǿ��Ϊ10������������Դ˲���
    template <typename T>
    T toNumber(int base = 10) const
    {
        T t = T();
        basic_stringstream<_Elem, _Traits, _Ax> ss(_Myptr());
        return ConvertToNumber<_Elem, _Traits, _Ax>(ss, t, base);
    }

    //������ת��Ϊ�ַ���
    // base:������������Ϊ8,10,16���������ֵ��ǿ��Ϊ10
    template <typename T>
    static _Myt fromNumber(T number, int base = 10)
    {
        basic_stringstream<_Elem, _Traits, _Ax> ss;
        ss.setf(BaseFlag(base), ios_base::basefield);
        ss << number;
        return ss.str();
    }

    //��floatת��Ϊ�ַ���
    // f:��ʽ������������Ϊ'f','e','E','g','G'��'f'Ϊ������,'e'��'E'��ʾ��ѧ������
    //	'g'��G����ʾ��ʽ��Ϊ���������ѧ������������һ����ʾ���㡣
    // prec:С������λ��(��������ʾ��)���ܵ���Чλ��(��ѧ������)
    static _Myt fromNumber(float number, _Elem f = _Elem('g'), int prec = 6)
    {
        return fromNumber(static_cast<double>(number), f, prec);
    }

    //��doubleת��Ϊ�ַ�������������ͬ��
    static _Myt fromNumber(double number, _Elem f = _Elem('g'), int prec = 6)
    {
        basic_stringstream<_Elem, _Traits, _Ax> ss;
        ss << setprecision(prec);
        if (_Traits::eq(f, _Elem('f')))
            ss << setiosflags(ios_base::fixed);
        else if (_Traits::eq(f, _Elem('e')) || _Traits::eq(f, _Elem('E')))
            ss << setiosflags(ios_base::scientific);
        ss << number;
        return ss.str();
    }
#pragma endregion // convert between numbers

#pragma region "format string"

    //��szFormat��ʽ��Ϊ�ַ�������������ͬsprintf
    void format(const _Elem *szFormat, ...)
    {
        if (!szFormat)
            return;
        va_list argList;
        va_start(argList, szFormat);
        formatV(szFormat, argList);
        va_end(argList);
    }

    //��szFormat��ʽ��Ϊ�ַ�������������ͬsprintf
    void formatV(const _Elem *szFormat, va_list argList)
    {
        if (!szFormat)
            return;
        int nLength = _ExTraits::ct_vscprintf(szFormat, argList);
        if (nLength < 0)
            return;
        resize(nLength);
        _ExTraits::ct_vstprintf_s(_Myptr(), nLength + 1, szFormat, argList);
        va_end(argList);
    }
#pragma endregion // format string
};

typedef basic_exstring<char, char_traits<char>,
                       allocator<char>, ex_char_traits<char>>
    exstring;

typedef basic_exstring<wchar_t, char_traits<wchar_t>,
                       allocator<wchar_t>, ex_char_traits<wchar_t>>
    exwstring;