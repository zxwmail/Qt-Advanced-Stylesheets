#ifndef StyleManagerH
#define StyleManagerH
//============================================================================
/// \file   StyleManager.h
/// \author Uwe Kindler
/// \date   13.12.2021
/// \brief  Declaration of CStyleManager class
//============================================================================

//============================================================================
//                                   INCLUDES
//============================================================================
#include <QString>
#include <QVector>
#include <QPair>
#include <QObject>

class QIcon;

namespace acss
{
struct StyleManagerPrivate;
using QStringPair = QPair<QString, QString>;

/**
 * Encapsulates all information about a single stylesheet
 */
class CStyleManager : public QObject
{
	Q_OBJECT
private:
	StyleManagerPrivate* d; ///< private data (pimpl)
	friend struct StyleManagerPrivate;

public:
	enum eError
	{
		NoError,
		CssTemplateError,
		CssExportError,
		ThemeXmlError,
		StyleJsonError,
		ResourceGeneratorError,
	};
	/**
	 * Default Constructor
	 */
	CStyleManager(QObject* parent = nullptr);

	/**
	 * Virtual Destructor
	 */
	virtual ~CStyleManager();

	/**
	 * Set the directory path that contains all styles
	 */
	void setStylesDir(const QString& DirPath);

	/**
	 * Returns the set styles dir
	 */
	QString stylesDir() const;

	/**
	 * Set the current style
	 */
	bool setCurrentStyle(const QString& Style);

	/**
	 * Returns the current style
	 */
	QString currentStyle() const;

	/**
	 * Returns the folder of the current style.
	 */
	QString currentStyleFolder() const;

	/**
	 * Returns the list of available styles in the given styles directory
	 */
	const QStringList& styles() const;

	/**
	 * Returns the folder with the resource template
	 */
	QString resourcesTemplatesFolder() const;

	/**
	 * Returns the folders that contains all themes for the current style
	 */
	QString themesFolder() const;

	/**
	 * Returns the fonts folder for the theme fonts of the current style
	 */
	QString fontsFolder() const;

	/**
	 * The output dir path where the generated files will get stored
	 */
	QString outputDirPath() const;

	/**
	 * Sets the output directory path where the generated theme will be stored
	 */
	void setOutputDirPath(const QString& Path);

	/**
	 * Returns the theme color for the given ColorId.
	 * For example themeColor("primaryColor") may return "#ac2300".
	 * Returns an empty string, if the given ColorId does not exist
	 */
	QString themeVariable(const QString& VariableId) const;

	/**
	 * You can use this function to set or overwrite a theme variable
	 */
	void setThemeVariabe(const QString& VariableId, const QString& Value);

	/**
	 * Sets the theme to use.
	 * Returns true on success and false on error
	 */
	bool setTheme(const QString& Theme);

	/**
	 * Returns the processed theme stylesheet
	 */
	QString styleSheet() const;

	/**
	 * Returns the icon for the current style
	 */
	const QIcon& styleIcon() const;


signals:
	/**
	 * This signal is emitted if the selected style changed
	 */
	void currentStyleChanged(const QString& Style);

	/**
	 * This signal is emitted, if the selected theme in a style changed
	 */
	void currentThemeChanged(const QString& Theme);
}; // class StyleManager
}
 // namespace namespace_name
//-----------------------------------------------------------------------------
#endif // StyleManagerH
