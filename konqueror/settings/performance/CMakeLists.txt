


########### next target ###############

set(kcm_performance_PART_SRCS kcmperformance.cpp konqueror.cpp system.cpp )


kde4_add_ui_files(kcm_performance_PART_SRCS konqueror_ui.ui system_ui.ui )

kde4_add_plugin(kcm_performance ${kcm_performance_PART_SRCS})


target_link_libraries(kcm_performance  ${KDE4_KDEUI_LIBS} )

install(TARGETS kcm_performance  DESTINATION ${PLUGIN_INSTALL_DIR} )


########### install files ###############

install( FILES kcmkonqyperformance.desktop kcmperformance.desktop  DESTINATION  ${SERVICES_INSTALL_DIR} )

