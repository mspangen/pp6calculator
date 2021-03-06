#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <fstream>
#include <string>
#include <sstream>

class FileReader {
 public:
  FileReader(const char* filename);
  FileReader(const std::string& filename);

  bool nextLine();

  int getFieldAsInt(const int n);
  float getFieldAsFloat(const int n);
  double getFieldAsDouble(const int n);
  std::string getFieldAsString(const int n);

template <typename T>
T getField(const int n) {
	failed = false;
	std::istringstream ist(line);
	this->skip_fields(ist, n-1);
	T rval = T();
	ist >> rval;
	if (ist.fail()) {
		failed = true;
		return T(0);
	}
	else
		return rval;
}


  bool inputFailed() const;
  bool isValid() const;

 private:
  void skip_fields(std::istringstream& ist, const int n);
  std::ifstream file;
  std::string line;
  bool failed;
};

#endif
