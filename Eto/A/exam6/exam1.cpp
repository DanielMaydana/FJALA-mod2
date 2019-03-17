#include <iostream>
#include <string>
using namespace std;

struct node
{
      string name;
      node* next;
};


class Linked_list
{
private:
      node* first;
      node* last;
      size_t count;
public:
      Linked_list()
      :first{nullptr}, last{nullptr}, count{0}
      { }

      ~Linked_list() { }

      node* push_back(node* new_node)
      {
            if(first)
            {
                  new_node->next = first;
                  first = new_node;
            }
            else
            {
                  first = last = new_node;

            }
            return new_node;
      }
};


class album : public node
{
private:
      size_t year;
public:
      album(const string& album_name, size_t year) 
      :node{album_name, nullptr}, year{year}
      { }

      ~album() { }

      void add_song(size_t track, const string song_name)
      {
            
      }
};

class artist : public node
{
private:
      Linked_list album_list;
public:
      artist(const string& name) 
      :node{name, nullptr}
      { }
      ~artist() { }

      album& add_album(const string& album_name, size_t album_year)
      {
            album* new_album = new album{album_name, album_year};
            album* album_return = static_cast<album*>(album_list.push_back(new_album));
            return *album_return;
      }
};


class music_catalogue
{
private:
      Linked_list artist_list;
public:
      music_catalogue() { }
      
      ~music_catalogue() { }

      artist& add_artist(const string& artist_name)
      {
            artist* new_artist = new artist{artist_name};
            artist* artist_return = static_cast<artist*> (artist_list.push_back(new_artist));
            return *artist_return; 
      }
};

void populate(music_catalogue& m)
{
      auto& psb = m.add_artist("pet shop boys");
      auto& dm = m.add_artist("depeche mode");
      
      auto& please = psb.add_album("please", 1985);
      auto& actually = psb.add_album("actually", 1987);
      auto& introspective = psb.add_album("introspective", 1988);
      auto& behaviour = psb.add_album("behaviour", 1990);
      auto& very = psb.add_album("very", 1993);              

      auto& sns = dm.add_album("speak and spell", 1981);
      auto& sgr = dm.add_album("some great reward", 1984);
      auto& bc = dm.add_album("black celebration", 1986);
      auto& mfm = dm.add_album("music for the masses", 1987);
      auto& v = dm.add_album("violator", 1990);             

      please.add_song(2, "West end girls");
      // please.add_song(3, "Opportunities");
      // please.add_song(4, "Love comes quickly");
      // please.add_song(5, "Suburbia");          

      // actually.add_song(2, "What have I done to deserve this?");
      // actually.add_song(4, "Rent");
      // actually.add_song(7, "It's a sin");
      // actually.add_song(9, "Heart");

      // introspective.add_song(1, "Left to my own devices");
      // introspective.add_song(3, "Domino dancing");
      // introspective.add_song(5, "Always on my mind");

      // behaviour.add_song(1, "Being boring");
      // behaviour.add_song(4, "How can you expect to be taken seriously?");
      // behaviour.add_song(7, "So hard");
      // behaviour.add_song(10, "Jealousy");              

      // very.add_song(1, "Can you forgive her?");
      // very.add_song(2, "I wouldn'nt normally do this kind of thing");
      // very.add_song(3, "Liberation");
      // very.add_song(4, "Yesterday, when I was mad");
      // very.add_song(12, "Go west");           

      // sns.add_song(1, "New life");
      // sns.add_song(11, "Just can't get enough");
      // sns.add_song(12, "Dreaming of me");

      // sgr.add_song(3, "People are people");
      // sgr.add_song(6, "Somebody");
      // sgr.add_song(7, "Master and servant");
      // sgr.add_song(9, "Blasphemous rumours");              

      // bc.add_song(3, "A question of lust");
      // bc.add_song(6, "A question of time");
      // bc.add_song(7, "Stripped");
      // bc.add_song(12, "But not tonight");

      // mfm.add_song(1, "Never let me down");
      // mfm.add_song(3, "Strangelove");
      // mfm.add_song(5, "Little 15");
      // mfm.add_song(6, "Behind the wheel");

      // v.add_song(1, "World in my eyes");
      // v.add_song(3, "Personal Jesus");
      // v.add_song(6, "Enjoy the silence");
      // v.add_song(7, "Policy of truth");              
}

int main()
{
     music_catalogue m;
     populate(m);

//      m.iterate_all_albums([](auto& s) { cout << s << endl; });
//      cout << "****************************" << endl;

//      m.iterate_albums_by_artist("depeche mode", [](auto& a)
//      {
//            cout << a << endl;
//            a.iterate_songs([](auto& s) { cout << "- " << s << endl; });
//      });
//      cout << "****************************" << endl;

//      m.iterate_albums_by_year(1987, [](auto& a) { cout << a << endl; });
//      cout << "****************************" << endl;

//      auto n = 0;
//      m.iterate_songs_that_start_with("W", [&n](auto& s)
//      {
//            auto& artist = s.get_artist();
//            auto& album = s.get_album();

//            cout << "Artist: " << artist << endl;
//            cout << "Album: " << album << endl;
//            cout << "Song: " << s << endl << endl;
//            n++;
//      });
//      cout << "NUMBER OF SONGS THAT START WITH W: " << n << endl;
//      cout << "****************************" << endl;

//      m.iterate_songs_by_year(1990, [] (auto& s)
//      {
//            cout << s.get_artist() << ": " << s << endl;
//      });

//      auto nn = m.count_songs_by_artist("depeche mode");
//      cout << "Depeche Mode songs: " << nn << endl;

//      auto ss = m.count_songs_by_artist("erasure");
//      cout << "Erasure songs: " << ss << endl;

     return 0;
}