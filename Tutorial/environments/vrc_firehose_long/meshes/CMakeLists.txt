set (files 
  coupling_hexagon.dae
  nozzle.stl
  connector.dae
)

install(FILES ${files} DESTINATION ${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}-${DRC_SIM_VERSION}/gazebo_models/environments/${MODEL_NAME}/meshes)
