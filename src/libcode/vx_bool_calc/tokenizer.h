

////////////////////////////////////////////////////////////////////////


#ifndef  __TOKENIZER_H__
#define  __TOKENIZER_H__


////////////////////////////////////////////////////////////////////////


#include "token.h"


////////////////////////////////////////////////////////////////////////


class Tokenizer {

   private:

      void init_from_scratch();

      int get_number();

      const char * source;   //  allocated, nul-terminated

      int pos;               //  next unread character

   public:

      Tokenizer();
     ~Tokenizer();

      void clear();

      void set(const char * input);

      Token next_token();

};


////////////////////////////////////////////////////////////////////////


#endif   /*  __TOKENIZER_H__  */


////////////////////////////////////////////////////////////////////////

