#ifndef LIEGE_H
#define LIEGE_H

enum class LiegeTyp { Standard = 0, Premium = 1 };

class LiegeStandard {
public:
  explicit LiegeStandard(int zustand = 100);
  virtual ~LiegeStandard() = default;

  bool istBelegt() const;
  bool buchen();
  bool stornieren();

  int zustand() const;

protected:
  int zustand_;
  bool belegt;
};

class LiegePremium : public LiegeStandard {
public:
  LiegePremium(int zustand, int anzKissen);

  int anzahlKissen() const;

private:
  int anzKissen_;
};

#endif // LIEGE_H
