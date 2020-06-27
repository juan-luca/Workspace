#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* ll)
{
    int returnAux = -1;

    if(ll!=NULL)
    {
        returnAux = ll->size;
    }


    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */



static Node* getNode(LinkedList* ll, int nodeIndex)
{
    Node* pNode = NULL;



    int len;


    if(ll!=NULL && nodeIndex>=0)
    {

        len=ll_len(ll);
        if(nodeIndex<len)
        {
            pNode=ll->pFirstNode;

            for(int i=0;i<len;i++)
            {

                if(i==nodeIndex)
                {
                    break;
                }
                pNode=pNode->pNextNode;

            }
        }else
        {
          pNode=NULL;
        }



    }else
    {
        pNode=NULL;
    }






    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* ll, int nodeIndex, void* pElement)
{
    int returnAux = -1;
    Node* prev=NULL;
    Node* next=NULL;
    Node* nuevoNodo=NULL;

    int len;


    if(ll!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(ll))
    {
        nuevoNodo=(Node*) malloc(sizeof(Node));

        nuevoNodo->pElement=pElement;
        len=ll_len(ll);


            if(nodeIndex==0)
            {
                if(ll->pFirstNode==NULL || len==0)
                {

                    ll->pFirstNode=nuevoNodo;
                    returnAux=0;

                }else
                {

                    next=getNode(ll,nodeIndex);
                    ll->pFirstNode=nuevoNodo;
                    nuevoNodo->pNextNode=next;
                    returnAux=0;

                }

            }else
            {
                if(nodeIndex==len)
                {
                    prev=getNode(ll,nodeIndex-1);
                    next=NULL;
                    prev->pNextNode=nuevoNodo;
                    nuevoNodo->pNextNode=next;
                    returnAux=0;
                }else
                {
                    prev=getNode(ll,nodeIndex-1);
                    next=getNode(ll,nodeIndex);
                    prev->pNextNode=nuevoNodo;
                    nuevoNodo->pNextNode=next;
                    returnAux=0;
                }


            }
    }


        if(returnAux==0)
        {

            ll->size++;
        }

    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* ll, void* pElement)
{
    int returnAux = -1;

    if(ll!=NULL)
    {

        if(addNode(ll,ll_len(ll),pElement)==0)
        {
            returnAux=0;
        }


    }




    return returnAux;
}
//  ******* OJO CORREGIR *******************
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* ll, int index)
{
    void* returnAux = NULL;
    Node* nodo = NULL;

    if(ll!=NULL && index>=0 && index<ll_len(ll))
    {


        nodo=getNode(ll,index);
        returnAux=nodo->pElement;

    }



    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* ll, int index,void* pElement)
{
    int returnAux = -1;
    Node* actual=NULL;
    //int cantidad;

    if(ll!=NULL && index>=0 && index<ll_len(ll))
    {


        actual=getNode(ll,index);
        actual->pElement=pElement;
        returnAux=0;

    }


    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* ll,int index)
{
    int returnAux = -1;
    Node* nodeToDelete;
    Node* aux;


    if(ll!=NULL && index>=0 && index<ll_len(ll))
    {
        nodeToDelete=getNode(ll,index);

        if(index==0)
        {
            ll->pFirstNode=nodeToDelete->pNextNode;

        }else
        {
            aux=getNode(ll,index-1);
            aux->pNextNode=nodeToDelete->pNextNode;
        }


        free(nodeToDelete);
        ll->size--;
        returnAux=0;

    }



    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* ll)
{
    int returnAux = -1;
    Node* nodo;
    int i;

    if(ll!=NULL )
    {

        for(i=ll_len(ll);i>0;i--)
        {
            if(i==0)
            {
                nodo=getNode(ll,i);
                ll->pFirstNode=NULL;
                free(nodo);
                ll->size--;
            }else
            {
                nodo=getNode(ll,i);
                free(nodo);
                ll->size--;
            }



        }


        if(ll->size==0)
        {
          returnAux=0;
        }


    }



    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* ll)
{
    int returnAux = -1;

    if(ll!=NULL)
    {
        free(ll);
        returnAux=0;
    }


    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* ll, void* pElement)
{
    int returnAux = -1;
    int i=0;
    Node* nodo;

    if(ll!=NULL)
    {

        nodo=ll->pFirstNode;
        for(i=0;i<ll_len(ll);i++)
        {
            if(nodo->pElement==pElement)
            {
                returnAux=i;
                break;
            }
            nodo=nodo->pNextNode;
        }


    }



    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* ll)
{
    int returnAux = -1;

    if(ll != NULL)
    {
        if(ll_len(ll))
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* ll, int index, void* pElement)
{
    int returnAux = -1;


    if(ll!=NULL && index>=0 && index<ll_len(ll)+1)
    {
        addNode(ll,index,pElement);
        returnAux=0;

    }


    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* ll,int index)
{

      void* returnAux = NULL;

    if(ll!=NULL && index>=0 && index<ll_len(ll))
    {
    	returnAux=ll_get(ll,index);
    	ll_remove(ll,index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* ll, void* pElement)
{
    int returnAux = -1;
    Node* nodo;
    int i;
    if(ll!=NULL)
    {
        returnAux=0;
        nodo=ll->pFirstNode;
        for(i=0;i<ll_len(ll);i++)
        {
            if(ll_indexOf(ll,pElement)!=-1)
            {
                returnAux=1;
                break;
            }

            nodo=nodo->pNextNode;
        }


    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* ll,LinkedList* ll2)
{
    int returnAux = -1;
    int i;
    int j=0;
    Node* nodo;
     Node* nodo2;
    if(ll!=NULL && ll2!=NULL)
    {
        if(ll->size == ll2->size)
        {
                returnAux=0;
                nodo=ll->pFirstNode;
                nodo2=ll2->pFirstNode;

                for(i=0;i<ll_len(ll);i++)
                {
                    if(ll_contains(ll,nodo2->pElement)!=-1)
                    {
                        j++;
                    }

                    nodo=nodo->pNextNode;
                    nodo2=nodo2->pNextNode;
                }


        }

                if(i==j)
                {
                    returnAux=1;
                }else
                {
                    returnAux=-1;
                }


    }




    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* ll,int from,int to)
{

    LinkedList* clonelist = NULL;





    void* pElement;
     if(ll!=NULL && from>=0 && to>=from && to<=ll_len(ll))

    {
        clonelist = ll_newLinkedList();


			for(int i=from;i<to;i++)
			{
				pElement=ll_get(ll,i);
				ll_add(clonelist,pElement);
			}


    }



    return clonelist;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/


LinkedList* ll_clone(LinkedList* ll)
{
    LinkedList* cloneArray = NULL;

    cloneArray=ll_subList(ll,0,ll_len(ll));


    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* ll, int (*pFunc)(void*,void*), int order)
{



    int returnAux =-1;
	    void* pAux;
	    void* pAuxI;
	    void* pAuxJ;

	    if (ll != NULL && ll->size > 1  && pFunc != NULL && (order == 1 || order == 0))
	    {


	        for(int i = 0; i < ll->size - 1; i++)
	        {
	            for(int j = i + 1; j < ll->size; j++)
	            {
	                pAuxI = ll_get(ll, i);
	                pAuxJ = ll_get(ll, j);

                    switch(order)
                    {
                            case 0:

                                if( pFunc(pAuxI, pAuxJ) == -1 )
                                {
                                    pAux = pAuxI;
                                    ll_set(ll, i, pAuxJ);
                                    ll_set(ll, j, pAux);
                                }

                                break;

                            case 1:

                                 if( pFunc(pAuxI, pAuxJ) == 1 )
                                {
                                    pAux = pAuxI;
                                    ll_set(ll, i, pAuxJ);
                                    ll_set(ll, j, pAux);
                                }

                                break;
                    }

	            }
	        }
	        returnAux = 0;
	    }



    return returnAux;
}

