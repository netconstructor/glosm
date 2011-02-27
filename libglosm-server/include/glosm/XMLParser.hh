/*
 * Copyright (C) 2010-2011 Dmitry Marakasov
 *
 * This file is part of glosm.
 *
 * glosm is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * glosm is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with glosm.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef XMLPARSER_HH
#define XMLPARSER_HH

#include <glosm/Exception.hh>

/**
 * Excepion that denotes XML parsing error
 */
class ParsingException : public Exception {
};

/**
 * Base class for all XML parsers
 */
class XMLParser {
protected:
	/**
	 * Static wrapper for StartElement
	 */
	static void StartElementWrapper(void* userData, const char* name, const char** atts);

	/**
	 * Static wrapper for EndElement
	 */
	static void EndElementWrapper(void* userData, const char* name);

	/**
	 * Processes start XML element
	 */
	virtual void StartElement(const char* name, const char** atts) = 0;

	/**
	 * Processes end XML element
	 */
	virtual void EndElement(const char* name) = 0;

protected:
	/**
	 * Constructs empty datasource
	 */
	XMLParser();

	/**
	 * Destructor
	 */
	virtual ~XMLParser();

public:
	/**
	 * Parses OSM dump file and loads map data into memory
	 *
	 * @param filename path to dump file
	 */
	virtual void Load(const char* filename);
};

#endif
