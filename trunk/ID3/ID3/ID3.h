#ifndef ID3_H_
#define ID3_H_

//#include <memory>

//#include <faif/ExceptionsFaif.h>
//#include <faif/Attribute.h>
//#include <faif/Domain.h>

#include <faif/learning/Classifier.h>
//#include <faif/learning/ExampleTrain.h>

using namespace faif::ml;

class ID3Impl;

class ID3 : public Classifier {

	public:

		ID3();
	    
		virtual ~ID3();

        AttrDomain& insertAttr(const std::string& id);

		AttrDomain& findAttrRef(const std::string& id);

		AttrDomain::iterator insertCategory(const std::string& id);

		virtual void reset();

		virtual void addTraining(const ExampleTrain&);

		virtual AttrVal getCategory(const ExampleTest&) const;

		friend std::ostream& operator<<(std::ostream&, const ID3&);

	private:
	    
		ID3(const ID3&);
	    
		ID3& operator=(const ID3&);

		std::auto_ptr<ID3Impl> impl_;
};

#endif