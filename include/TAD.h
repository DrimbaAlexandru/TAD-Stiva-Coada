#ifndef TAD_H
#define TAD_H

#include "DinVect.h"

#define DIM_COADA 1000

template <typename elem>
class nod
{
private:
    nod* urm;
    elem data;

public:
    nod(){this->urm=NULL;}
    nod(elem data)
    {
        this->data=data;
        this->urm=NULL;
    }
    nod(nod* urm, elem data)
    {
        this->urm=urm;
        this->data=data;
    }
    nod(const nod& other)
    {
        urm=other.urm;
        data=other.data;
    }
    ~nod(){}
    void operator= (const nod& other)
    {
        urm=other.urm;
        data=other.data;
    }
    nod* get_next()
    {
        return urm;
    }
    elem get_data()
    {
        return data;
    }
    void set_next(nod* next)
    {
        urm=next;
    }
    void set_data(elem new_data)
    {
        data=new_data;
    }
};

template <typename elem>
class stiva
{
private:
    nod<elem>* prim;

public:

    stiva()
    {
        prim=NULL;
    }
    stiva(const stiva& other)
    {
        prim=NULL;
        nod<elem> *q,*ant,*p=prim;
        while(p!=NULL)
        {
            q=p;
            p=p->get_next();
            delete q;
        }

        if(other.prim==NULL)
            {prim=NULL;
            return;}
        else
            prim=new nod<elem>(*other.prim);
            p=other.prim->get_next();
            ant=prim;
            while(p!=NULL)
            {
                q=new nod<elem>(*p);
                ant->set_next(q);
                p=p->get_next();
                ant=q;
            }
    }
    void operator=(const stiva& other)
    {
        nod<elem> *q,*ant,*p=prim;
        while(p!=NULL)
        {
            q=p;
            p=p->get_next();
            delete q;
        }

        if(other.prim==NULL)
            {prim=NULL;
            return;}
        else
            prim=new nod<elem>(*other.prim);
            p=other.prim->get_next();
            ant=prim;
            while(p!=NULL)
            {
                q=new nod<elem>(*p);
                ant->set_next(q);
                p=p->get_next();
                ant=q;
            }
    }

    void push(const elem& e)
    {
        nod<elem>* p=new nod<elem>(prim,e);
        prim=p;
    }

    elem pop()
    {
        elem e;
        e=prim->get_data();
        nod<elem> *p=prim;
        prim=prim->get_next();
        delete p;
        return e;
    }

    elem get_varf()
    {
        return prim->get_data();
    }

    int is_empty()
    {
        return prim==NULL;
    }
};
//--------------------------------------------------------------------
template <typename elem>
class coada
{
private:
    elem data[DIM_COADA];
    int urm[DIM_COADA];
    int prim;
    int prim_liber;

public:

    coada()
    {
        prim=-1;
        prim_liber=0;
        int i;
        for(i=0;i<DIM_COADA;i++)
            urm[i]=-1;
    }
    coada(const coada& other)
    {
        int i;
        for(i=0;i<DIM_COADA;i++)
        {
            data[i]=other.data[i];
            urm[i]=other.urm[i];
        }
        prim=other.prim;
        prim_liber=other.prim_liber;
    }
    void operator=(const coada& other)
    {
        int i;
        for(i=0;i<DIM_COADA;i++)
        {
            data[i]=other.data[i];
            urm[i]=other.urm[i];
        }
        prim=other.prim;
        prim_liber=other.prim_liber;
    }

    void push(const elem& e)
    {
        int curent=prim;
        if(prim==-1)
        {
            curent=0;
            prim=0;
        }
        else
        {
            while(urm[curent]!=-1)
                curent=urm[curent];
            urm[curent]=prim_liber;
        }
        data[prim_liber]=e;
        urm[prim_liber]=-1;
        prim_liber=(prim_liber+1)%DIM_COADA;
    }

    elem pop()
    {
        elem e=data[prim];
        int prim2=prim;
        prim=urm[prim];
        urm[prim2]=-1;
        if(prim==-1)
            prim_liber=0;
        return e;
    }

    elem get_varf()
    {
        return data[prim];
    }

    int is_empty()
    {
        return prim==-1;
    }
};

#endif // TAD_H
