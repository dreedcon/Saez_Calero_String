#ifndef _P2MAP_H_
#define _P2MAP_H_

#include "p2Defs.h"
#include "p2List.h"
template <typename...> class p2Map;

template <class TYPE, class TYPE2>
class p2Map<TYPE, TYPE2>{
public:
	struct NodeMap
	{
		TYPE key;
		TYPE2 value;

		NodeMap(const TYPE& data, const TYPE& key) : value(data), key(key)
		{}
	};

private:
	p2List<NodeMap*> map;
	

public:
	NodeMap* push_back(const TYPE& data, const TYPE& key)
	{
		p2List<NodeMap*>::node* tmp = map.front_node();
		TYPE data_compare;
		while (tmp != NULL){
			data_compare = key;
				if (key == tmp->data->key){
					return nullptr;
				}
				tmp = tmp->next();
		}
		NodeMap* new_vertice = new NodeMap(data, key);
		map.push_back(new_vertice);
		return new_vertice;
	}

	// Operators ----------------------------------------------------------
	TYPE2* operator[](TYPE k)
	{
		p2List<NodeMap*>::node* tmp = map.front_node();
		while (tmp != NULL){
		
			if (k == tmp->data->key){
				return (&tmp->data->value);
			}
			tmp = tmp->next();
		}
		
		return NULL;
	}

	bool Empty() const{
		return map.empty();
	}

	uint Size() const{
		return map.size();
	}

	void Clear(){
		const p2List<NodeMap*>::node* p = map.front_node();
		while (p != nullptr)
		{
			RELEASE(p->data);
			p = p->next();
		}
		map.clear();
	}

};

#endif