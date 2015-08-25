#ifndef ID3IMPL_H_
#define ID3IMPL_H_

//#include <memory>
//#include <list>

//#include "NaiveBayesianRoot.h"

using namespace faif::ml;

typedef std::list<AttrDomain> Attributes;


class ID3Impl {

	public:

		ID3Impl();
		
		~ID3Impl();

		/** accessor, dostarcza atrybutow */
		Attributes& getAttributes(){ return attributes_; }
		/** accessor, dostarcza atrybutow */
		AttrDomain& getCategories(){ return CategoriesDomain_; }


		/** metoda zmienia stan klasyfikatora na taki, jaki byl przed nauczeniem sie czegokolwiek */
		void reset();

		/** metoda dodaje przyklad trenujacy. */
		void addTraining(const ExampleTrain& example);

		/** metoda klasyfikuje podany przyklad */
		AttrVal getCategory(const ExampleTest& example);

		/** globalna funkcja, wypisuje zawartosc klasyfikatora */
		friend std::ostream& operator<<(std::ostream& os, const NaiveBayesianImpl& nb);
	private:
		/** noncopyable */
		ID3Impl(const ID3Impl&);
		/** noncopyable */
		ID3Impl& operator=(const ID3Impl&);

		Attributes attributes_; //!< przechowuje atrybuty i wartosci
		AttrDomain CategoriesDomain_;
		ExamplesTrain examplestrain_;
		//ID3Categories categories_; //!< przechowuje kategorie i odp. liczniki
		//std::auto_ptr<NaiveBayesianRoot> classifier_; //!< obiekt przetwarzajacy informacje
};

#endif
