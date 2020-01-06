#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))
using namespace std;
struct avl {
   int d;
   struct avl *l;
   struct avl *r;
}*r;
class avl_tree {
   public:
      int height(avl*);
      int difference(avl*);
      avl* rr_rotat(avl*);
      avl* ll_rotat(avl*);
      avl* lr_rotat(avl*);
      avl* rl_rotat(avl*);
      avl* balance(avl*);
      avl* insert(avl*, int);
      void inorder(avl*);
      void preorder(avl*);
      avl_tree() {
         r = NULL;
      }
};
int avl_tree::height(avl* t) {
   int h = 0;
   if (t != NULL) {
      int l_height = height(t->l);
      int r_height = height(t->r);
      int max_height = max(l_height, r_height);
      h = max_height + 1;
   }
   return h;
}
int avl_tree::difference(avl* t) {
   int l_height = height(t->l);
   int r_height = height(t->r);
   int b_factor = l_height - r_height;
   return b_factor;
}
avl *avl_tree::rr_rotat(avl* parent) {
   avl *t;
   t = parent->r;
   parent->r = t->l;
   t->l = parent;
   return t;
}
avl *avl_tree::ll_rotat(avl* parent) {
   avl *t;
   t = parent->l;
   parent->l = t->r;
   t->r = parent;
   return t;
}
avl *avl_tree::lr_rotat(avl* parent) {
   avl *t;
   t = parent->l;
   parent->l = rr_rotat(t);
   return ll_rotat(parent);
}
avl *avl_tree::rl_rotat(avl* parent) {
   avl *t;
   t = parent->r;
   parent->r = ll_rotat(t);
   return rr_rotat(parent);
}
avl *avl_tree::balance(avl* t) {
   int bal_factor = difference(t);
   if (bal_factor > 1) {
      if (difference(t->l) > 0)
         t = ll_rotat(t);
      else
         t = lr_rotat(t);
   } else if (bal_factor < -1) {
      if (difference(t->r) > 0)
         t = rl_rotat(t);
      else
         t = rr_rotat(t);
   }
   return t;
}
avl *avl_tree::insert(avl* r, int v) {
   if (r == NULL) {
      r = new avl;
      r->d = v;
      r->l = NULL;
      r->r = NULL;
      return r;
   } else if (v< r->d) {
      r->l = insert(r->l, v);
      r = balance(r);
   } else if (v >= r->d) {
      r->r = insert(r->r, v);
      r = balance(r);
   } return r;
}
void avl_tree::inorder(avl* t) {
   if (t == NULL)
      return;
      inorder(t->l);
      cout << t->d << " ";
      inorder(t->r);
}
void avl_tree::preorder(avl* t) {
   if (t == NULL)
      return;
      cout << t->d << " ";
      preorder(t->l);
      preorder(t->r);
}

int main() {

   int c, i;
   avl_tree avl;
   while (1) {
      cout << "1.Adauga un element in arbore\n";
      cout << "2.SDR\n";
      cout << "3.RSD\n";
      cout << "Optiune: ";
      cin >> c;
      switch (c) {
         case 1:
            cout << "element = ";
            cin >> i;
            r = avl.insert(r, i);
         break;
         case 2:
            cout << "SRD:" << endl;
            avl.inorder(r);
            cout << endl;
         break;
         case 3:
            cout << "RSD:" << endl;
            avl.preorder(r);
            cout << endl;
         break;
      }
   }
   return 0;
}
