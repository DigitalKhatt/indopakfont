#pragma once
#include "GlyphVis.h"
#include "Lookup.h"
#include "Subtable.h"
#include "automedina.h"

namespace indopak {

class IndoPak : public Automedina {
 public:
  IndoPak(OtLayout* layout, Font* font, bool extended);
  Lookup* getLookup(QString lookupName) override;
  CalcAnchor getanchorCalcFunctions(QString functionName, Subtable* subtable) override;
  CursiveAnchorFunc getCursiveFunctions(QString functionName, Subtable* subtable) override;
  ~IndoPak() {}

 private:
  Lookup* defaultmarkposition();
  Lookup* waqfMarkPositioning();
  Lookup* waqfMkmkPositioning();
  Lookup* forsmallhighwaw();
  Lookup* forhamza();
  Lookup* forheh();
  Lookup* cursivejoin();
  Lookup* cursivejoinrtl();
  Lookup* pointmarks();
  Lookup* defaultdotmarks();
  Lookup* defaultmarkdotmarks();
  Lookup* defaultmkmk();
  Lookup* ayanumbers();
  Lookup* ayanumberskern();
  Lookup* rehwawcursivecpp();
  Lookup* allCursiveJoin(bool rtl);
  Lookup* populatecvxx();
  Lookup* glyphalternates();
  // Justification
  Lookup* shrinkstretchlt(float lt, QString featureName);
  Lookup* shrinkstretchlt();
  void addchars();
  void generateGlyphs();
  void generateAyas(QString ayaName, bool colored, int unicode);
  /*using LookupFunction = void (IndoPak::*)();
  std::map<QString, LookupFunction> lookups;*/
  // for Core Text. See bug https://github.com/DigitalKhatt/madinafont/issues/21
  bool isForCoreText = false;
};
class Waqffinabasemark : public AnchorCalc {
 public:
  Waqffinabasemark(Automedina& y, MarkBaseSubtable& subtable) : _y(y), _subtable(subtable) {}
  QPoint operator()(QString glyphName, QString className, QPoint adjust, GlyphParameters parameters) override {
    GlyphVis& curr = _y.glyphs[glyphName];

    int width = curr.width / 2 + adjust.x();
    int height = 0;

    return QPoint(width, height);
  };

 private:
  Automedina& _y;
  MarkBaseSubtable& _subtable;
};
class Waqffinamark : public AnchorCalc {
 public:
  Waqffinamark(Automedina& y, MarkBaseSubtable& subtable) : _y(y), _subtable(subtable) {}
  QPoint operator()(QString glyphName, QString className, QPoint adjust, GlyphParameters parameters) override {
    GlyphVis& curr = _y.glyphs[glyphName];

    int width = curr.width / 2 + adjust.x();
    int height = curr.height + 30 + adjust.y();

    return QPoint(width, height);
  };

 private:
  Automedina& _y;
  MarkBaseSubtable& _subtable;
};
class Waqfbasebelow : public AnchorCalc {
 public:
  Waqfbasebelow(Automedina& y, MarkBaseSubtable& subtable) : _y(y), _subtable(subtable) {}
  QPoint operator()(QString glyphName, QString className, QPoint adjust, GlyphParameters parameters) override {
    GlyphVis& curr = _y.glyphs[glyphName];

    int width = curr.width / 2 + adjust.x();
    int height = curr.height + 30 + adjust.y();

    return QPoint(width, height);
  };

 private:
  Automedina& _y;
  MarkBaseSubtable& _subtable;
};
class Waqfmarkabove : public AnchorCalc {
 public:
  Waqfmarkabove(Automedina& y, MarkBaseSubtable& subtable) : _y(y), _subtable(subtable) {}
  QPoint operator()(QString glyphName, QString className, QPoint adjust, GlyphParameters parameters) override {
    GlyphVis& curr = _y.glyphs[glyphName];

    int width = curr.width / 2 + adjust.x();
    int height = 0;

    return QPoint(width, height);
  };

 private:
  Automedina& _y;
  MarkBaseSubtable& _subtable;
};
class AfterRehWaw {
 public:
  AfterRehWaw(Automedina& y, MarkBaseSubtable& subtable) : _y(y), _subtable(subtable) {}
  QPoint operator()(bool entry, GlyphVis* originalglyph, GlyphVis* extendedglyph) {
    if (entry) {
      QPoint entry = QPoint(extendedglyph->width, 0);

      return entry;
    } else {
      return QPoint(0, 0);
    }
  };

 private:
  Automedina& _y;
  MarkBaseSubtable& _subtable;
};

}  // namespace indopak
