deps_config := \
	juicevmconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
