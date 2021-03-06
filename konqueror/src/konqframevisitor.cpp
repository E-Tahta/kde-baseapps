/*
   This file is part of the KDE project
   Copyright (C) 2007 David Faure <faure@kde.org>

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#include "konqframevisitor.h"
#include "konqframe.h"
#include "konqview.h"

bool KonqViewCollector::visit(KonqFrame* frame)
{
    m_views.append(frame->childView());
    return true;
}

QList<KonqView *> KonqViewCollector::collect(KonqFrameBase* topLevel)
{
    KonqViewCollector collector;
    topLevel->accept(&collector);
    return collector.m_views;
}

bool KonqLinkableViewsCollector::visit(KonqFrame* frame)
{
    if (!frame->childView()->isFollowActive())
        m_views.append(frame->childView());
    return true;
}

QList<KonqView *> KonqLinkableViewsCollector::collect(KonqFrameBase* topLevel)
{
    KonqLinkableViewsCollector collector;
    topLevel->accept(&collector);
    return collector.m_views;
}

bool KonqModifiedViewsCollector::visit(KonqFrame* frame)
{
    KonqView* view = frame->childView();
    if (view && view->isModified()) {
        m_views.append(view);
    }
    return true;
}

QList<KonqView *> KonqModifiedViewsCollector::collect(KonqFrameBase* topLevel)
{
    KonqModifiedViewsCollector collector;
    topLevel->accept(&collector);
    return collector.m_views;
}

