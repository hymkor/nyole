#ifndef WIN32COM_H
#define WIN32COM_H

#include <windows.h>

class Unicode {
    BSTR w;
    int enc;
public:
    static BSTR  c2b(const char *s,int enc_); // To free, SysFreeString(r);
    static BSTR  c2b(const char *s,size_t csize,int enc);
    static char *b2c(BSTR w,int enc_); // To free, delete[]r;

    Unicode(const char *s,int enc_) : w(c2b(s,enc_)),enc(enc_){}
    ~Unicode(){ if(w){ SysFreeString(w); } }

    operator const BSTR &(){ return w; }
    BSTR *operator &(){ return &w; }
    char *toChar(){ return b2c(w,this->enc); } // To free, delete[]r;
};

class Variants {
    VARIANTARG *v;
    int size_;
    void grow();
public:
    Variants() : v(NULL),size_(0){}
    ~Variants();

    operator VARIANTARG*(){ return v; }
    void add_as_string( const char *s , int enc);
    void add_as_number( double d );
    void add_as_boolean( int n );
    void add_as_null();
    VARIANT *add_anything();
    size_t size(){ return size_; }
};

class ActiveXObject {
    static int instance_count;
    IDispatch *pApplication;
    IDispatch *toFree;
    HRESULT construct_error_;
    int enc1;
public:
    int enc() const { return this->enc1; }
    explicit ActiveXObject(const char *name,bool isNewInstance,int enc);
    explicit ActiveXObject(IDispatch *p,int enc);
    ~ActiveXObject();

    int invoke(const char *name,
            WORD wflags ,
            VARIANT *argv ,
            int argc ,
            VARIANT &result ,
            HRESULT *hr=0,
            char **error_info=0 
            );
    int const_load(void *L,void (*setter)(void *,const char *,VARIANT &,int enc));

    int ok() const { return pApplication != NULL ; }
    HRESULT construct_error() const { return construct_error_; }

    IDispatch *getIDispatch(){ return pApplication; }
};

class ActiveXMember {
    ActiveXObject &instance_;
    DISPID dispid_;
    HRESULT construct_error_;
    int enc1;
public:
    int enc() const { return this->enc1; }
    ActiveXMember( ActiveXObject &instance , const char *name );
    DISPID dispid() const { return dispid_; }
    int invoke(WORD wflags,VARIANT *argv , int argc , VARIANT &result,HRESULT *hr=0,char **error_info=0 );

    int ok() const { return ! FAILED(construct_error_); }
    HRESULT construct_error() const { return construct_error_; }
    ActiveXObject &instance(){ return instance_; }
};

class ActiveXIterator {
    IEnumVARIANT  *pEnumVariant_;
    VARIANT        var_;
    bool status_;
    int  enc1;
public:
    ActiveXIterator( ActiveXObject &parent );
    ~ActiveXIterator();
    bool ok() const { return status_; }
    bool nextObj();

    VARIANT        &var(){ return var_; }
    int enc() const { return this->enc1; }
};

#endif
