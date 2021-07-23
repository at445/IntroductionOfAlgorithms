#pragma once
#include <vector>
namespace HeapSort {
	template <typename Ty_>
	struct Heap {
		int size;
		std::vector<Ty_> * p;
	};

	inline int Parent(int i)
	{
		return i / 2;
	}

	inline int ChildRight(int i)
	{
		return i * 2 + 1;
	}

	inline int ChildLeft(int i)
	{
		return i * 2;
	}
	template <typename Ty_>
	inline void Swap(Ty_& a, Ty_& b)
	{
		Ty_ temp = a;
		a = b;
		b = temp;
	}

	template <typename Ty_>
	inline int MaxAddress(struct Heap<Ty_>& hp, int lo, int ro)
	{
		if ((lo > hp.size) && (ro > hp.size)) return -1;
		if (lo > hp.size) return ro;
		if (ro > hp.size) return lo;

		if (hp.p->at(lo - 1) > hp.p->at(ro - 1)) return lo;
		else return ro;
	}

	template <typename Ty_>
	void AdjustHeap(struct Heap<Ty_>& hp, int i)
	{
		if (i > hp.size / 2) {
			return;
		}
		int tmp = MaxAddress(hp, i, ChildLeft(i));
		tmp = MaxAddress(hp, tmp, ChildRight(i));
		if (tmp == i) return;
		Swap(hp.p->at(i - 1), hp.p->at(tmp - 1));
		AdjustHeap(hp, tmp);
	}

	template <typename Ty_>
	void BuildHeap(struct Heap<Ty_>& hp)
	{
		for (int i = hp.size/2; i >= 1; i--) {
			AdjustHeap(hp, i);
		}
	} 

	template <typename Ty_>
	Ty_ GetMax(struct Heap<Ty_>& hp)
	{
		return hp.p->at(0);
	}

	template <typename Ty_>
	Ty_ PopMax(struct Heap<Ty_>& hp)
	{
		Swap(hp.p->at(0), hp.p->at(hp.size-1));
		hp.size -= 1;
		AdjustHeap(hp, 1);
		Ty_ ret = hp.p->back();
		hp.p->pop_back();
		return ret;
	}

	template <typename Ty_>
	void InsertIntoHeap(struct Heap<Ty_>& hp, int loc, Ty_ val)
	{
		if (hp.p->at(loc - 1) > val) return;
		
		while ((loc > 1) && (hp.p->at(Parent(loc)-1) < val)) {
			Swap(hp.p->at(loc - 1) , hp.p->at(Parent(loc)-1));
			loc = Parent(loc);
		}
	}


	template <typename Ty_>
	void InsertIntoHeap(struct Heap<Ty_>& hp, Ty_ val)
	{
		hp.p->push_back(val);
		hp.size += 1;
		InsertIntoHeap(hp, hp.size, val);
	}


	template <typename Ty_>
	void HeapSort(std::vector<Ty_>& vc)
	{
		struct Heap<Ty_> hp;
		hp.size = vc.size();
		hp.p = &vc;
		BuildHeap(hp);
		for (int i = 1; i <= vc.size(); i++)
		{
			Swap(vc[0], vc[vc.size() - i]);
			hp.size -= 1;
			AdjustHeap(hp, 1);
		}
	}
}